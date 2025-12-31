#include "pg.h"

int pg_read(FILE *fp, pg_t *pgp)
{
    if (fscanf(fp, "%s %s %s", pgp->cod, pgp->nome, pgp->classe) == 3)
    {
        stat_read(fp, &(pgp->b_stat));
        pgp->eq_stat = pgp->b_stat;
        pgp->equip = equipArray_init();
        return 1;
    }
    return 0;
}

void pg_clean(pg_t *pgp)
{
    if (pgp == NULL)
        printf("\nPersonaggio inesistente.\n");
    else
        equipArray_free(pgp->equip);
}

void pg_print(FILE *fp, pg_t *pgp, invArray_t invArray)
{
    if (pgp == NULL)
        printf("\nPersonaggio inesistente.\n");
    else
    {
        fprintf(fp, "\nCod: %-10s\t\tName: %-10s\t\tClass: %-10s\t\tBase Stat: ", pgp->cod, pgp->nome, pgp->classe);
        stat_print(fp, &(pgp->b_stat), INT_MAX);
        equipArray_print(fp, pgp->equip, invArray);
        fprintf(fp, "Eq Stat: ");
        stat_print(fp, &(pgp->eq_stat), 1);
    }
}

void pg_updateEquip(pg_t *pgp, invArray_t invArray) { 
    equipArray_update(pgp->equip, invArray, &(pgp->eq_stat)); 
}