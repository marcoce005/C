#include "equipArray.h"

struct equipArray_s
{
    int inUso;
    inv_t *vettEq[EQUIP_SLOT];
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

void equipArray_print(FILE *fp, equipArray_t equipArray, invArray_t invArray) {}

void equipArray_update(equipArray_t equipArray, invArray_t invArray) {
    
}

int equipArray_getEquipByIndex(equipArray_t equipArray, int index) {}