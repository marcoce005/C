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
    char buf[BUF_SIZE], buf1[BUF_SIZE];
    int exit = 0, input;
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

            stocks = Stock_list_get_from_file(stocks, fp);
            fclose(fp);
            break;

        case search_stock:
            printf("\nInsert stock's code:\n--> ");
            scanf("%s", buf);

            selected = Stock_list_search_by_code(stocks, buf);
            Stock_print(selected);
            break;

        case search_quotation:
            printf("\nInsert stock's code:\n--> ");
            scanf("%s", buf);
            selected = Stock_list_search_by_code(stocks, buf);
            printf("\nInsert date of quotation [format YYYY/MM/DD]:\n--> ");
            scanf("%s", buf);
            Stock_search_quotation(selected, buf);
            break;

        case get_min_max_quotation:
            printf("\nInsert stock's code:\n--> ");
            scanf("%s", buf);
            selected = Stock_list_search_by_code(stocks, buf);
            printf("\nInsert the start date [format YYYY/MM/DD]:\n--> ");
            scanf("%s", buf);
            printf("\nInsert the end date [format YYYY/MM/DD]:\n--> ");
            scanf("%s", buf1);
            Stock_search_min_max_quotations_beetwen_dates(selected, buf, buf1);
            break;

        case balance_tree:
            printf("\nInsert stock's code:\n--> ");
            scanf("%s", buf);
            selected = Stock_list_search_by_code(stocks, buf);
            printf("\nInsert the threshold:\n--> ");
            scanf("%d", &input);
            Stock_balance_BST(selected, input);
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