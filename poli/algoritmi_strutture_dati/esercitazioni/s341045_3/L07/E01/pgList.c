#include "pgList.h"

typedef struct nodoPg_s *link;
typedef struct nodoPg_s
{
    pg_t pg;
    link next;
} nodoPg_t;

struct pgList_s
{
    link headPg,
        tailPg;
    int nPg;
};

pgList_t pgList_init()
{
    pgList_t pgList = (pgList_t)malloc(sizeof(*pgList));
    pgList->nPg = 0;
    pgList->headPg = pgList->tailPg = NULL;
    return pgList;
}

static void free_list(link h)
{
    if (h == NULL)
        return;
    free_list(h->next);
    free(h);
}

void pgList_free(pgList_t pgList)
{
    free_list(pgList->headPg);
    free(pgList);
}

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

void pgList_read(FILE *fp, pgList_t pgList)
{
    if (fp == NULL)
    {
        printf("\nFile error: file not found or corrupted.\n");
        exit(1);
    }

    pg_t tmp;
    int end = pg_read(fp, &(tmp));
    for (; end; (pgList->nPg)++, end = pg_read(fp, &(tmp)))
        list_ins(&(pgList->headPg), &(pgList->tailPg), tmp);
}

static void print_list(FILE *fp, link h, invArray_t invArray)
{
    if (h == NULL)
        return;
    pg_print(fp, &(h->pg), invArray);
    print_list(fp, h->next, invArray);
}

void pgList_print(FILE *fp, pgList_t pgList, invArray_t invArray) { print_list(fp, pgList->headPg, invArray); }

void pgList_insert(pgList_t pgList, pg_t pg) { list_ins(&(pgList->headPg), &(pgList->tailPg), pg); }

void pgList_remove(pgList_t pgList, char *cod)
{
    link x, p;
    if (pgList->nPg == 0)
        printf("\nRemove error: empty list of character\n");
    else
    {
        for (x = pgList->headPg, p = NULL; x != NULL; p = x, x = x->next)
            if (strcmp(x->pg.cod, cod) == 0)
            {
                if (pgList->headPg == pgList->tailPg)
                    pgList->headPg = pgList->tailPg = NULL;
                else if (x == pgList->headPg)
                    pgList->headPg = x->next;
                else if (x == pgList->tailPg)
                {
                    pgList->tailPg = p;
                    p->next = NULL;
                }
                else
                    p->next = x->next;
                free(x);
                (pgList->nPg)--;
                return;
            }
    }
}

pg_t *pgList_searchByCode(pgList_t pgList, char *cod)
{
    link x, p;
    for (p = NULL, x = pgList->headPg; x != NULL; p = x, x = x->next)
        if (strcmp(x->pg.cod, cod) == 0)
            return &(x->pg);
    return NULL;
}