#include <stdio.h>

#include "stocks.h"

#define BUF_SIZE 128

typedef enum
{
    get_file,
    search_stock,
    search_quotation,
    get_min_max_quotation,
    balance_tree,
    quit
} command_t;

int main(void)
{
    FILE *fp = NULL;
    char buf[BUF_SIZE];
    int exit = 0;
    command_t action;
    Stock_list stocks = NULL;
    Stock selected;

    while (!exit)
    {
        printf("\nSelect the action:\n");
        printf(" - 0 [get information from file]\n");
        printf(" - 1 [search a stock]\n");
        printf(" - 2 [search the quotation of a stock by date]\n");
        printf(" - 3 [get min and max quotation of a stock]\n");
        printf(" - 4 [balance the tree of quotation of a stock]\n");
        printf(" - 5 [quit]\n--> ");
        scanf("%d", (int *)&action);

        switch (action)
        {
        case get_file:
            printf("\nInsert path file [ex. F1.txt]:\n--> ");
            scanf("%s", buf);

            fp = fopen(buf, "r");
            if (fp == NULL)
            {
                printf("\nFile not found.\n");
                break;
            }

            stocks = Stock_get_from_file(fp);
            fclose(fp);
            break;

        case search_stock:
            printf("\nInsert stock's code:\n--> ");
            scanf("%s", buf);
            
            selected = Stock_search_by_code(stocks, buf);
            Stock_print(selected);
            break;

        case search_quotation:
            /* code */
            break;

        case get_min_max_quotation:
            /* code */
            break;

        case balance_tree:
            /* code */
            break;

        case quit:
            exit = 1;
            Stock_list_free(stocks);
            break;

        default:
            printf("\nCommand not found.\n");
            break;
        }
    }

    return 0;
}