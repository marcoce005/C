#include <stdlib.h>
#include <string.h>

#include "stocks.h"
#include "prices.h"

#define STOCK_COD_LEN 20 + 1

struct stock
{
    char code[STOCK_COD_LEN];
    int n_transaction;
    Prices quotations;
};

typedef struct node_s *link;
typedef struct node_s
{
    Stock stock;
    link next;
} node_t;

struct list_stocks
{
    link head;
    int n;
};

Stock Stock_init(char *code, int transaction)
{
    Stock x = (Stock)malloc(sizeof(*x));
    strcpy(x->code, code);
    x->n_transaction = transaction;
    x->quotations = Prices_BST_init();
    return x;
}

void Stock_free(Stock s)
{
    Prices_BST_free(s->quotations);
    free(s);
}

void Stock_print(Stock s)
{
    if (s == NULL)
        printf("\nStock not found.\n");
    else
        printf("\nCode --> %s\nTransaction --> %d\n", s->code, s->n_transaction);
}

Stock_list Stock_list_init(void)
{
    Stock_list l = (Stock_list)malloc(sizeof(*l));
    l->n = 0;
    l->head = NULL;
    return l;
}

static void list_free(link h)
{
    if (h == NULL)
        return;
    list_free(h->next);
    Stock_free(h->stock);
    free(h);
}

void Stock_list_free(Stock_list s)
{
    if (s == NULL)
        return;
    list_free(s->head);
    free(s);
}

static link new_node(Stock stock, link next)
{
    link x = (link)malloc(sizeof(*x));
    x->stock = stock;
    x->next = next;
    return x;
}

static link list_ins(link h, char *code, int transaction)
{
    if (h == NULL || strcmp(h->stock->code, code) > 0)
        return new_node(Stock_init(code, transaction), h);

    link x, p;
    for (p = h, x = h->next; x != NULL && strcmp(x->stock->code, code) > 0; p = x, x = x->next)
        ;
    p->next = new_node(Stock_init(code, transaction), x);
    return h;
}

Stock_list Stock_get_from_file(FILE *fp_in)
{
    Stock_list l = Stock_list_init();
    char buf[STOCK_COD_LEN];
    int i, j, n, *arr_values, *arr_qty;
    datetime_t *arr_date;

    fscanf(fp_in, "%d", &l->n);

    for (i = 0; i < l->n; i++)
    {
        fscanf(fp_in, "%s %d", buf, &n);
        l->head = list_ins(l->head, buf, n);

        arr_date = (datetime_t *)malloc(n * sizeof(datetime_t));
        arr_values = (int *)malloc(n * sizeof(int));
        arr_qty = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            arr_date[j] = init_datetime(fp_in);
            fscanf(fp_in, "%d %d", arr_values + j, arr_qty + j);
        }
        Prices_BST_fill(l->head->stock->quotations, arr_date, arr_values, arr_qty, n);

        free(arr_date);
        free(arr_values);
        free(arr_qty);
    }
    return l;
}

static Stock search_list(link h, char *code)
{
    if (h == NULL)
        return NULL;

    if (strcmp(h->stock->code, code) == 0)
        return h->stock;
    search_list(h->next, code);
}

Stock Stock_search_by_code(Stock_list l, char *code) { return search_list(l->head, code); }