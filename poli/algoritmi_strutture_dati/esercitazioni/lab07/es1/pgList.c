#include "pgList.h"

struct pgList_s
{
};

pgList_t pgList_init()
{
}

void pgList_free(pgList_t pgList)
{
}

void pgList_read(FILE *fp, pgList_t pgList)
{
}

void pgList_print(FILE *fp, pgList_t pgList, invArray_t invArray)
{
}

void pgList_insert(pgList_t pgList, pg_t pg)
{
}

void pgList_remove(pgList_t pgList, char *cod)
{
}

pg_t *pgList_searchByCode(pgList_t pgList, char *cod)
{
}