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

#endif