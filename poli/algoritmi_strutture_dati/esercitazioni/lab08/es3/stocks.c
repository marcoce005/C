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
    {
        printf("\nCode --> %s\nTransaction --> %d\n", s->code, s->n_transaction);
        Prices_BST_print(s->quotations);
        printf("\n");
    }
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

Stock_list Stock_list_get_from_file(Stock_list l, FILE *fp_in)
{
    if (l == NULL)
        l = Stock_list_init();

    char buf[STOCK_COD_LEN];
    int i, j, n, *arr_values, *arr_qty;
    datetime_t *arr_date;

    fscanf(fp_in, "%d", &l->n);

    for (i = 0; i < l->n; i++)
    {
        fscanf(fp_in, "%s %d", buf, &n);

        if (Stock_list_search_by_code(l, buf) == NULL)
            l->head = list_ins(l->head, buf, n);
        else
            Stock_list_search_by_code(l, buf)->n_transaction += n;

        arr_date = (datetime_t *)malloc(n * sizeof(datetime_t));
        arr_values = (int *)malloc(n * sizeof(int));
        arr_qty = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            arr_date[j] = datetime_from_file(fp_in);
            fscanf(fp_in, "%d %d", arr_values + j, arr_qty + j);
        }
        Prices_BST_fill(Stock_list_search_by_code(l, buf)->quotations, arr_date, arr_values, arr_qty, n);

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

Stock Stock_list_search_by_code(Stock_list l, char *code)
{
    if (l == NULL)
    {
        printf("\nYou have to get informations from file before search.\n");
        return NULL;
    }
    return search_list(l->head, code);
}

void Stock_search_quotation(Stock s, char *date)
{
    if (s == NULL)
    {
        Stock_print(s);
        return;
    }

    datetime_t datetime = datetime_from_str(strcat(date, " 00:00"));

    datetime_print(stdout, datetime);
    printf("\n%s\n", date);

    float ans = Prices_BST_search(s->quotations, datetime);
    if (ans < 0)
    {
        printf("\nQuotation in date ");
        datetime_print(stdout, datetime);
        printf(" not found.\n");
    }
    else
        printf("\nQuotation in date %04d/%02d/%02d is %.2f$.\n", datetime.YYYY, datetime.MM, datetime.DD, ans);
}

void Stock_search_min_max_quotations_beetwen_dates(Stock s, char *d0, char *d1)
{
    if (s == NULL)
    {
        Stock_print(s);
        return;
    }

    datetime_t d_min = datetime_from_str(strcat(d0, " 00:00")),
               d_max = datetime_from_str(strcat(d1, " 00:00")),
               tmp;

    if (date_compare(d_min, d_max) > 0)
    {
        tmp = d_min;
        d_min = d_max;
        d_max = tmp;
    }
    Prices_BST_min_max_beetwen_dates(s->quotations, d_min, d_max);
}

void Stock_balance_BST(Stock s, int S)
{
    if (s == NULL)
    {
        Stock_print(s);
        return;
    }
    Prices_BST_balance(s->quotations, S);
}