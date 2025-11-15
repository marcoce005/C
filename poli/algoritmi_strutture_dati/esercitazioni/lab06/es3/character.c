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

void add_obj_2_equip(obj val_p, pg character)
{
    if (character->equip.inUso == MAX_OBJ)
        printf("\nYou can't add object to equipment, it's full.\n");
    else
    {
        character->equip.vettEq[character->equip.inUso] = val_p;
        character->equip.inUso++;
    }
}

void remove_obj_2_equip(obj object, pg character)
{
    int i, new_index;
    for (i = new_index = 0; i < character->equip.inUso; i++)
        if (character->equip.vettEq[i] != object)
            character->equip.vettEq[new_index++] = character->equip.vettEq[i];
        else
            character->equip.inUso--;
}

void print_character(pg x)
{
    if (x == NULL)
        printf("\nCharacter not found\n");
    else
    {
        printf("\nCod: %s\t\tName: %s\t\tClass: %s\n", x->codice, x->nome, x->classe);
        printf("hp: %d\n", x->stat.hp);
        printf("mp: %d\n", x->stat.mp);
        printf("atk: %d\n", x->stat.atk);
        printf("def: %d\n", x->stat.def);
        printf("mag: %d\n", x->stat.mag);
        printf("spr: %d\nEquip [n-objects: %d]:\n", x->stat.spr, x->equip.inUso);

        for (int i = 0; i < x->equip.inUso; i++)
        {
            printf(" - ");
            print_obj(x->equip.vettEq[i]);
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
    if (tab->headPg == NULL)
        printf("\nRemove error: empty list of character\n");
    else
    {
        for (x = tab->headPg, p = NULL; x != NULL; p = x, x = x->next)
            if (strcmp(x->pg.codice, code) == 0)
            {
                if (x == tab->headPg)
                    tab->headPg = x->next;
                else
                    p->next = x->next;
                free(x);
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
}