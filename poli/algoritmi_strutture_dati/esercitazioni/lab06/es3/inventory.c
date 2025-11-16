#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

#define MAX_LEN_STR 50 + 1

typedef struct Stat
{
    int hp, mp, atk, def, mag, spr;
} stat_t;

struct Obj
{
    char nome[MAX_LEN_STR],
        tipo[MAX_LEN_STR];
    stat_t stat;
};

struct inv_t
{
    struct Obj *vettInv;
    int nInv,
        maxInv;
};

stat_p get_object_stat(obj object_p)
{
    return &(object_p->stat);
}

obj search_obj_by_name(tabInv_t tab, char *name)
{
    for (int i = 0; i < tab->maxInv; i++)
        if (strcmp(tab->vettInv[i].nome, name) == 0)
            return &(tab->vettInv[i]);
    return NULL;
}

void print_obj(obj object_p)
{
    if (object_p == NULL)
        printf("\nObject not found\n");
    else
    {
        printf("Name: %s\t\tType: %s\t\tStat: {", object_p->nome, object_p->tipo);
        printf("hp: %d,  ", object_p->stat.hp);
        printf("mp: %d,  ", object_p->stat.mp);
        printf("atk: %d,  ", object_p->stat.atk);
        printf("def: %d,  ", object_p->stat.def);
        printf("mag: %d,  ", object_p->stat.mag);
        printf("spr: %d}\n", object_p->stat.spr);
    }
}

tabInv_t get_inventory(char *path)
{
    FILE *fp = fopen(path, "r");
    tabInv_t tab = (tabInv_t)malloc(sizeof(*tab));

    if (fp == NULL)
    {
        printf("\nFile error:\n file %s not found or corrupted.\n", path);
        exit(1);
    }

    fscanf(fp, "%d", &(tab->maxInv));

    tab->nInv = tab->maxInv;
    tab->vettInv = (struct Obj *)malloc(tab->maxInv * sizeof(struct Obj));

    for (int i = 0; i < tab->maxInv; i++)
    {
        fscanf(fp, "%s %s %d %d %d %d %d %d",
               (tab->vettInv)[i].nome,
               (tab->vettInv)[i].tipo,
               &(tab->vettInv[i].stat.hp),
               &(tab->vettInv[i].stat.mp),
               &(tab->vettInv[i].stat.atk),
               &(tab->vettInv[i].stat.def),
               &(tab->vettInv[i].stat.mag),
               &(tab->vettInv[i].stat.spr));
    }

    fclose(fp);
    return tab;
}

void free_inventory(tabInv_t tab) {
    free(tab->vettInv);
    free(tab);
}