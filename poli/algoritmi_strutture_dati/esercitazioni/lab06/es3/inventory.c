#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

#define MAX_LEN_STR 50 + 1
#define MAX_STAT 6

struct Obj
{
    char nome[MAX_LEN_STR],
        tipo[MAX_LEN_STR];
    int stat[MAX_STAT];
};

struct inv_t
{
    struct Obj *vettInv;
    int nInv,
        maxInv;
};

obj search_obj_by_name(tabInv_t tab, char *name)
{
    for (int i = 0; i < tab->maxInv; i++)
        if (strcmp(tab->vettInv[i].nome, name) == 0)
            return &(tab->vettInv[i]);
    return NULL;
}

void print_obj(obj x)
{
    if (x == NULL)
        printf("\nObject not found\n");
    else
    {
        printf("Name: %s\t\tType: %s\t\tStat: ", x->nome, x->tipo);
        for (int i = 0; i < MAX_STAT; printf("%d ", x->stat[i]), i++)
            ;
        printf("\n");
    }
}

tabInv_t get_inventory(char *path)
{
    FILE *fp = fopen(path, "r");
    tabInv_t tab = (tabInv_t)malloc(sizeof(*tab));
    int i, j;

    if (fp == NULL)
    {
        printf("\nFile error:\n file %s not found or corrupted.\n", path);
        exit(1);
    }

    fscanf(fp, "%d", &(tab->maxInv));

    tab->nInv = tab->maxInv;
    tab->vettInv = (struct Obj *)malloc(tab->maxInv * sizeof(struct Obj));

    for (i = 0; i < tab->maxInv; i++)
    {
        fscanf(fp, "%s %s", (tab->vettInv)[i].nome, (tab->vettInv)[i].tipo);
        for (j = 0; j < MAX_STAT; fscanf(fp, "%d", &((tab->vettInv)[i].stat[j])), j++)
            ;
    }

    fclose(fp);
    return tab;
}