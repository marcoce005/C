#include <stdlib.h>

#include "prices.h"

typedef struct node *link;
struct node
{
    price_t item;
    link l,
        r;
};

struct BST_prices
{
    link root;
    int n_nodes;
};

Prices Prices_BST_init()
{
    Prices x = (Prices)malloc(sizeof(*x));
    x->n_nodes = 0;
    x->root = NULL;
    return x;
}

static void tree_free(link h)
{
    if (h == NULL)
        return;
    tree_free(h->l);
    tree_free(h->r);
    free(h);
}

void Prices_BST_free(Prices p)
{
    if (p == NULL)
        return;
    tree_free(p->root);
    free(p);
}

static link new_node(price_t val, link l, link r)
{
    link x = (link)malloc(sizeof(*x));
    x->item = val;
    x->l = l;
    x->r = r;
    return x;
}

static link BST_inf_leaf(link h, price_t val)
{
    if (h == NULL)
        return new_node(val, NULL, NULL);
    if (date_compare(val.date, h->item.date) < 0)
        h->l = BST_inf_leaf(h->l, val);
    else
        h->r = BST_inf_leaf(h->r, val);
    return h;
}

void Prices_BST_ins(Prices p, price_t item) { p->root = BST_inf_leaf(p->root, item); }

static float cal_quotation(int *vals, int *qtys, int n)
{
    int i, tot_stocks, tot;
    for (tot_stocks = tot = i = 0; i < n; tot += vals[i] * qtys[i], tot_stocks += qtys[i], i++)
        ;
    return tot / (float)tot_stocks;
}

void Prices_BST_fill(Prices p, datetime_t *dates, int *values, int *qtys, int n)
{
    int i, start, elems;
    price_t x;
    for (start = i = 0, elems = 1; i < n; i++)
    {
        if (i == n - 1 || date_compare(dates[i], dates[i + 1]) != 0)
        {
            x.date = dates[i];
            x.quotation = cal_quotation(values + start, qtys + start, elems);
            Prices_BST_ins(p, x);
            start = i + 1;
            elems = 1;
        }
        else
            elems++;
    }
}
