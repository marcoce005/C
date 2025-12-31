#include <stdlib.h>
#include <string.h>

#include "ST.h"

struct symbol_table
{
    int N, max_N;
    computer_t *v;
};

static computer_t item_void(void)
{
    computer_t x;
    x.id[0] = '\0';
    x.net[0] = '\0';
    return x;
}

ST ST_init(int max_elements)
{
    ST st = (ST)malloc(sizeof(*st));

    st->max_N = max_elements;
    st->N = 0;
    st->v = (computer_t *)malloc(st->max_N * sizeof(computer_t));

    for (int i = 0; i < st->max_N; i++)
        st->v[i] = item_void();

    return st;
}

void ST_free(ST st)
{
    free(st->v);
    free(st);
}

computer_t ST_search_by_index(ST st, int index) { return st->v[index]; }

int computer_is_void(computer_t x) { return x.id[0] == '\0' && x.net[0] == '\0'; }

int ST_search_by_computer_id(ST st, char *name)
{
    for (int i = 0; i < st->N; i++)
        if (strcmp(st->v[i].id, name) == 0)
            return i;
    return -1;
}

void ST_insert(ST st, computer_t value, int index)
{
    if (st->v == NULL)
        return;

    if (ST_search_by_computer_id(st, value.id) != -1)
        return;

    if (index >= st->max_N)
    {
        st->max_N *= 2;
        st->v = (computer_t *)realloc(st->v, st->max_N * sizeof(computer_t));
    }

    st->v[index] = value;
    (st->N)++;
}