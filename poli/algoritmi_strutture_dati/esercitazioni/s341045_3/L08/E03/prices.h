#ifndef _PRICES
#define _PRICES

#include "date_time.h"

typedef struct
{
    datetime_t date;
    float quotation;
} price_t;

typedef struct BST_prices *Prices;

Prices Prices_BST_init();

void Prices_BST_free(Prices p);

void Prices_BST_fill(Prices p, datetime_t *dates, int *values, int *qtys, int n);

void Prices_BST_ins(Prices p, price_t item);

void Prices_BST_print(Prices p);

float Prices_BST_search(Prices p, datetime_t date);

void Prices_BST_min_max_beetwen_dates(Prices p, datetime_t d_min, datetime_t d_max);

void Prices_BST_balance(Prices p, int S);

#endif