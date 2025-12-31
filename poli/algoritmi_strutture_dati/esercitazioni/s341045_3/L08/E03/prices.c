#include <stdlib.h>
#include <limits.h>

#include "prices.h"

typedef struct node *link;
struct node
{
    price_t item;
    link l,
        r;
    int n;
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

static link new_node(price_t val, link l, link r, int n)
{
    link x = (link)malloc(sizeof(*x));
    x->item = val;
    x->l = l;
    x->r = r;
    x->n = n;
    return x;
}

static link BST_ins_leaf(link h, price_t val)
{
    if (h == NULL)
        return new_node(val, NULL, NULL, 1);
    if (date_compare(val.date, h->item.date) < 0)
        h->l = BST_ins_leaf(h->l, val);
    else
        h->r = BST_ins_leaf(h->r, val);
    h->n++;
    return h;
}

void Prices_BST_ins(Prices p, price_t item)
{
    p->root = BST_ins_leaf(p->root, item);
    p->n_nodes++;
}

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

static void BST_print(link h)
{
    if (h == NULL)
        return;
    BST_print(h->l);
    datetime_print(stdout, h->item.date);
    printf("\nquotation --> %.2f\n", h->item.quotation);
    BST_print(h->r);
}

void Prices_BST_print(Prices p)
{

    if (p->root == NULL)
        printf("pippo\t%d", p->n_nodes);

    BST_print(p->root);
}

static float BST_search(link h, datetime_t date)
{
    if (h == NULL)
        return -1;
    if (date_compare(h->item.date, date) == 0)
        return h->item.quotation;
    if (date_compare(h->item.date, date) < 0)
        return BST_search(h->l, date);
    return BST_search(h->r, date);
}

float Prices_BST_search(Prices p, datetime_t date) { return BST_search(p->root, date); }

static void BST_min_max_beetwen_dates(link h, datetime_t d_min, datetime_t d_max, float *min, float *max)
{
    if (h == NULL)
        return;
    BST_min_max_beetwen_dates(h->l, d_min, d_max, min, max);

    if (date_compare(h->item.date, d_min) >= 0 && date_compare(h->item.date, d_max) <= 0)
    {
        if (h->item.quotation > *max)
            *max = h->item.quotation;
        if (h->item.quotation < *min)
            *min = h->item.quotation;
    }

    BST_min_max_beetwen_dates(h->r, d_min, d_max, min, max);
}

void Prices_BST_min_max_beetwen_dates(Prices p, datetime_t d_min, datetime_t d_max)
{
    float min = INT_MAX,
          max = -1;

    BST_min_max_beetwen_dates(p->root, d_min, d_max, &min, &max);

    if (min == INT_MAX && max == -1)
        printf("\nNo quotations beetwen %04d/%02d/%02d and %04d/%02d/%02d.\n", d_min.YYYY, d_min.MM, d_min.DD, d_max.YYYY, d_max.MM, d_max.DD);
    else
        printf("\nMin quotation --> %.2f\nMax quotation --> %.2f\n", min, max);
}

static void BST_max_path(link h, int pos, int *min_depth, int *max_depth)
{
    if (h == NULL)
        return;

    if (h->l == NULL && h->r == NULL)
    {
        if (pos > *max_depth)
            *max_depth = pos;
        if (pos < *min_depth)
            *min_depth = pos;
    }

    BST_max_path(h->l, pos + 1, min_depth, max_depth);
    BST_max_path(h->r, pos + 1, min_depth, max_depth);
}

static link BST_rot_right(link h)
{
    link x = h->l;
    h->l = x->r;
    x->r = h;
    x->n = h->n;
    h->n = 1 + (h->l != NULL ? h->l->n : 0) + (h->r != NULL ? h->r->n : 0);
    return x;
}

static link BST_rot_left(link h)
{
    link x = h->r;
    h->r = x->l;
    x->l = h;
    h->n = 1 + (h->l != NULL ? h->l->n : 0) + (h->r != NULL ? h->r->n : 0);
    return x;
}

static link BST_partition(link h, int r)
{
    int t = h->l != NULL ? h->l->n : 0;

    if (t > r)
    {
        h->l = BST_partition(h->l, r);
        h = BST_rot_right(h);
    }

    if (t < r)
    {
        h->r = BST_partition(h->r, r - t - 1);
        h = BST_rot_left(h);
    }

    return h;
}

static link BST_balance(link h)
{
    if (h == NULL)
        return NULL;

    int r = ((h->n + 1) / 2) - 1;
    h = BST_partition(h, r);
    h->l = BST_balance(h->l);
    h->r = BST_balance(h->r);

    return h;
}

void Prices_BST_balance(Prices p, int S)
{
    if (p->root->l == NULL && p->root->r == NULL)
    {
        printf("\nBST already balance.\n");
        return;
    }

    int min = INT_MAX,
        max = -1;

    BST_max_path(p->root, 0, &min, &max);

    printf("min --> %d\nmax --> %d\n", min, max);

    if (max / (float)min <= (float)S)
    {
        printf("\nBST already balance.\n");
        return;
    }

    p->root = BST_balance(p->root);
}