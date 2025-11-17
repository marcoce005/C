#include "invArray.h"

struct invArray_s
{
    inv_t *vettInv;
    int maxInv,
        nInv;
};

invArray_t invArray_init() { return (invArray_t)malloc(sizeof(struct invArray_s)); }

void invArray_free(invArray_t invArray)
{
    free(invArray->vettInv);
    free(invArray);
}

void invArray_read(FILE *fp, invArray_t invArray)
{
    if (fp == NULL)
    {
        printf("\nFile error:\n file not found or corrupted.\n");
        exit(1);
    }

    fscanf(fp, "%d", &(invArray->maxInv));
    invArray->vettInv = (inv_t *)malloc(invArray->maxInv * sizeof(inv_t));

    for (invArray->nInv = 0; invArray->nInv < invArray->maxInv; (invArray->nInv)++)
        inv_read(fp, invArray->vettInv + invArray->nInv);
}

void invArray_print(FILE *fp, invArray_t invArray)
{
    for (int i = 0; i < invArray->nInv; i++)
        invArray_printByIndex(fp, invArray, i);
}

void invArray_printByIndex(FILE *fp, invArray_t invArray, int index)
{
    if (invArray->nInv == 0)
        printf("\nInventario vuoto.\n");
    else if (index >= invArray->maxInv || index < 0)
        printf("\nIndice %d non valido.\n", index);
    else if (index >= invArray->nInv)
        printf("\nNon è presente nessun oggetto in posizione %d", index);
    else
        inv_print(fp, invArray->vettInv + index);
}

inv_t *invArray_getByIndex(invArray_t invArray, int index)
{
    if (invArray->nInv == 0)
        printf("\nInventario vuoto.\n");
    else if (index >= invArray->maxInv || index < 0)
        printf("\nIndice %d non valido.\n", index);
    else if (index >= invArray->nInv)
        printf("\nNon è presente nessun oggetto in posizione %d", index);
    else
        return invArray->vettInv + index;
    return NULL;
}

int invArray_searchByName(invArray_t invArray, char *name)
{
    for (int i = 0; i < invArray->maxInv; i++)
        if (strcmp(invArray->vettInv[i].nome, name) == 0)
            return i;
    return -1;
}