#include "inv.h"

void stat_read(FILE *fp, stat_t *statp)
{
    fscanf(fp, "%d %d %d %d %d %d",
           &(statp->hp),
           &(statp->mp),
           &(statp->atk),
           &(statp->def),
           &(statp->mag),
           &(statp->spr));
}

void stat_print(FILE *fp, stat_t *statp, int soglia)
{
    fprintf(fp, "Stat: {hp: %4d, ", soglia != INT_MAX && statp->hp < soglia ? soglia : statp->hp);
    fprintf(fp, "mp: %4d, ", soglia != INT_MAX && statp->mp < soglia ? soglia : statp->mp);
    fprintf(fp, "atk: %4d, ", soglia != INT_MAX && statp->atk < soglia ? soglia : statp->atk);
    fprintf(fp, "def: %4d, ", soglia != INT_MAX && statp->def < soglia ? soglia : statp->def);
    fprintf(fp, "mag: %4d, ", soglia != INT_MAX && statp->mag < soglia ? soglia : statp->mag);
    fprintf(fp, "spr: %4d}\n", soglia != INT_MAX && statp->spr < soglia ? soglia : statp->spr);
}

void inv_read(FILE *fp, inv_t *invp)
{
    fscanf(fp, "%s %s", invp->nome, invp->tipo);
    stat_read(fp, &(invp->stat));
}

void inv_print(FILE *fp, inv_t *invp)
{
    fprintf(fp, "Name: %-10s\t\tType: %-10s\t\t", invp->nome, invp->tipo);
    stat_print(fp, &(invp->stat), INT_MAX); // stampa senza soglia
}

stat_t inv_getStat(inv_t *invp) { return invp->stat; }