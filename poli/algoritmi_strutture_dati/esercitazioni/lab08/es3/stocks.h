#ifndef _STOCKS
#define _STOCKS

#include <stdio.h>

typedef struct stock *Stock;
typedef struct list_stocks *Stock_list;

Stock Stock_init(char *code, int transaction);

void Stock_free(Stock s);

void Stock_print(Stock s);

Stock_list Stock_list_init(void);

void Stock_list_free(Stock_list l);

Stock_list Stock_list_get_from_file(Stock_list l, FILE *fp_in);

Stock Stock_list_search_by_code(Stock_list l, char *code);

void Stock_search_quotation(Stock s, char *date);

void Stock_search_min_max_quotations_beetwen_dates(Stock s, char *d0, char *d1);

void Stock_balance_BST(Stock s, int S);

#endif