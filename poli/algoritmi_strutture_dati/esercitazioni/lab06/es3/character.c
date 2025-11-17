#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_STR 50 + 1
#define COD_LEN 6 + 1
#define MAX_OBJ 8

typedef struct TabEquip
{
    int inUso;
    obj vettEq[MAX_OBJ];
} tabEquip_t;

typedef struct Stat
{
    int hp, mp, atk, def, mag, spr;
} stat_t;

typedef struct Pg
{
    char codice[COD_LEN],
        nome[MAX_LEN_STR],
        classe[MAX_LEN_STR];
    tabEquip_t equip;
    stat_t stat;
} pg_t;

typedef struct NodoPg *link;
typedef struct NodoPg
{
    pg_t pg;
    link next;
} nodoPg_t;

struct TabPg
{
    link headPg,
        tailPg;
    int nPg;
};

static link new_node(pg_t val, link next)
{
    link x = (link)malloc(sizeof(*x));

    if (x == NULL)
    {
        printf("\nMalloc error in new_node.\n");
        exit(1);
    }

    x->pg = val;
    x->next = next;
    return x;
}

static void list_ins(link *head_p, link *tail_p, pg_t val)
{
    if (*head_p == NULL)
        *head_p = *tail_p = new_node(val, NULL);
    else
    {
        (*tail_p)->next = new_node(val, NULL);
        *tail_p = (*tail_p)->next;
    }
}

tabPg_t get_characters(char *path)
{
    FILE *fp = fopen(path, "r");
    tabPg_t tab = (tabPg_t)malloc(sizeof(*tab));
    pg_t val;
    int i;

    if (fp == NULL)
    {
        printf("\nFile error:\n file %s not found or corrupted.\n", path);
        exit(1);
    }

    tab->headPg = tab->tailPg = NULL;
    tab->nPg = 0;

    for (i = 0; fscanf(fp, "%s %s %s %d %d %d %d %d %d", val.codice, val.nome, val.classe, &val.stat.hp, &val.stat.mp, &val.stat.atk, &val.stat.def, &val.stat.mag, &val.stat.spr) == 9; i++)
    {
        val.equip.inUso = 0;
        list_ins(&(tab->headPg), &(tab->tailPg), val);
    }
    tab->nPg = i;

    fclose(fp);
    return tab;
}

void add_obj_2_equip(obj object_p, pg character_p)
{
    if (character_p->equip.inUso == MAX_OBJ)
        printf("\nYou can't add object if equipment it's full.\n");
    else
    {
        character_p->equip.vettEq[character_p->equip.inUso] = object_p;
        character_p->equip.inUso++;
    }
}

void remove_obj_2_equip(obj object_p, pg character_p)
{
    int i, new_index;

    if (character_p->equip.inUso == 0)
        printf("\nYou can't remove object if the equipment it's empty.\n");
    else
    {
        for (i = new_index = 0; i < character_p->equip.inUso; i++)
            if (character_p->equip.vettEq[i] != object_p)
                character_p->equip.vettEq[new_index++] = character_p->equip.vettEq[i];
            else
                character_p->equip.inUso--;
    }
}

void print_character(pg character_p)
{
    if (character_p == NULL)
        printf("\nCharacter not found\n");
    else
    {
        printf("\nCod: %s\t\tName: %s\t\tClass: %s\n", character_p->codice, character_p->nome, character_p->classe);
        printf("hp: %d\n", character_p->stat.hp);
        printf("mp: %d\n", character_p->stat.mp);
        printf("atk: %d\n", character_p->stat.atk);
        printf("def: %d\n", character_p->stat.def);
        printf("mag: %d\n", character_p->stat.mag);
        printf("spr: %d\nEquip [n-objects: %d]:\n", character_p->stat.spr, character_p->equip.inUso);

        for (int i = 0; i < character_p->equip.inUso; i++)
        {
            printf(" - ");
            print_obj(character_p->equip.vettEq[i]);
        }
    }
}

pg search_character_by_code(tabPg_t tab, char *code)
{
    for (link h = tab->headPg; h != NULL; h = h->next)
    {
        if (strcmp(h->pg.codice, code) == 0)
            return &(h->pg);
    }
    return NULL;
}

void remove_character(tabPg_t tab, char *code)
{
    link x, p;
    if (tab->nPg == 0)
        printf("\nRemove error: empty list of character\n");
    else
    {
        for (x = tab->headPg, p = NULL; x != NULL; p = x, x = x->next)
            if (strcmp(x->pg.codice, code) == 0)
            {
                if (tab->headPg == tab->tailPg)
                    tab->headPg = tab->tailPg = NULL;
                else if (x == tab->headPg)
                    tab->headPg = x->next;
                else if (x == tab->tailPg)
                {
                    tab->tailPg = p;
                    p->next = NULL;
                }
                else
                    p->next = x->next;
                free(x);
                (tab->nPg)--;
                return;
            }
    }
}

void insert_character(tabPg_t tab)
{
    pg_t val;
    val.equip.inUso = 0;

    printf("\nInsert character information:\nCode [format PGXXXX X are digits]: ");
    scanf("%s", val.codice);
    printf("Name: ");
    scanf("%s", val.nome);
    printf("Class: ");
    scanf("%s", val.classe);
    printf("\nInsert statistics [integer numbers]:\nhp: ");
    scanf("%d", &val.stat.hp);
    printf("mp: ");
    scanf("%d", &val.stat.mp);
    printf("atk: ");
    scanf("%d", &val.stat.atk);
    printf("def: ");
    scanf("%d", &val.stat.def);
    printf("mag: ");
    scanf("%d", &val.stat.mag);
    printf("spr: ");
    scanf("%d", &val.stat.spr);

    list_ins(&(tab->headPg), &(tab->tailPg), val);
    (tab->nPg)++;
}

void cal_statistics(pg character_p)
{
    struct Pg tmp = *character_p;
    stat_t stat;

    for (int i = 0; i < character_p->equip.inUso; i++)
    {
        stat = *get_object_stat(character_p->equip.vettEq[i]);
        tmp.stat.hp = (tmp.stat.hp + stat.hp <= 0) ? 0 : (tmp.stat.hp + stat.hp);
        tmp.stat.mp = (tmp.stat.mp + stat.mp <= 0) ? 0 : (tmp.stat.mp + stat.mp);
        tmp.stat.atk = (tmp.stat.atk + stat.atk <= 0) ? 0 : (tmp.stat.atk + stat.atk);
        tmp.stat.def = (tmp.stat.def + stat.def <= 0) ? 0 : (tmp.stat.def + stat.def);
        tmp.stat.mag = (tmp.stat.mag + stat.mag <= 0) ? 0 : (tmp.stat.mag + stat.mag);
        tmp.stat.spr = (tmp.stat.spr + stat.spr <= 0) ? 0 : (tmp.stat.spr + stat.spr);
    }
    print_character(&(tmp));
}

static void free_list_r(link h)
{
    if (h == NULL)
        return;
    free_list_r(h->next);
    free(h);
}

void free_characters(tabPg_t tab)
{
    free_list_r(tab->headPg);
    free(tab);
}