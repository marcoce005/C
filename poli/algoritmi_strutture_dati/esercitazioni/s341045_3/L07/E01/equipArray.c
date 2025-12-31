#include "equipArray.h"

struct equipArray_s
{
    int inUso;
    int vettEq[EQUIP_SLOT];
};

equipArray_t equipArray_init()
{
    equipArray_t equipArray = (equipArray_t)malloc(sizeof(*equipArray));
    equipArray->inUso = 0;
    return equipArray;
}

void equipArray_free(equipArray_t equipArray)
{
    free(equipArray);
}

int equipArray_inUse(equipArray_t equipArray) { return equipArray->inUso; }

void equipArray_print(FILE *fp, equipArray_t equipArray, invArray_t invArray)
{
    fprintf(fp, "Equip [object: %d]:\n", equipArray->inUso);
    for (int i = 0; i < equipArray->inUso; i++)
    {
        fprintf(fp, " - ");
        invArray_printByIndex(fp, invArray, equipArray->vettEq[i]);
    }
}

static void calc_eq_stat(int add, stat_t *eq_statp, stat_t x)
{
    int operand = add ? 1 : -1;
    eq_statp->hp += operand * (x.hp);
    eq_statp->mp += operand * (x.mp);
    eq_statp->atk += operand * (x.atk);
    eq_statp->def += operand * (x.def);
    eq_statp->mag += operand * (x.mag);
    eq_statp->spr += operand * (x.spr);
}

static void add_in_equip(equipArray_t equipArray, int index)
{
    if (equipArray->inUso == EQUIP_SLOT)
        printf("\nEquipaggiamento pieno.\n");
    equipArray->vettEq[(equipArray->inUso)++] = index;
}

/* 1 --> rimozione effettuata   0 --> rimozione non effettuata */
static int rm_in_equip(equipArray_t equipArray, int index)
{
    int i, j;
    for (i = 0; i < equipArray->inUso && equipArray->vettEq[i] != index; i++)
        ;

    if (equipArray->inUso > 0)
    {
        for (j = i + 1; j < equipArray->inUso; equipArray->vettEq[i] = equipArray->vettEq[j], j++, i++)
            ;
        (equipArray->inUso)--;
        return 1;
    }
    return 0;
}

void equipArray_update(equipArray_t equipArray, invArray_t invArray, stat_t *eq_statp)
{
    int index, add = 0;
    char search_name[LEN];

    printf("\n0 > Rimuovere un oggetto all'equipaggiamento\n1 > Aggiungere un oggetto all'equipaggiamento\n");
    scanf("%d", &add);
    printf("Inserire nome dell'oggetto: ");
    scanf("%s", search_name);

    index = invArray_searchByName(invArray, search_name);
    if (index < 0)
    {
        printf("\nOggetto non trovato.\n");
        return;
    }

    if (add)
    {
        add_in_equip(equipArray, index);
        calc_eq_stat(add, eq_statp, inv_getStat(invArray_getByIndex(invArray, index)));
    }
    else if (rm_in_equip(equipArray, index))
        calc_eq_stat(add, eq_statp, inv_getStat(invArray_getByIndex(invArray, index)));
}

int equipArray_getEquipByIndex(equipArray_t equipArray, int index)
{
    if (equipArray->inUso <= index || index < 0)
        return -1;
    return equipArray->vettEq[index];
}