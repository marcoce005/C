#include <stdio.h>

#include "Graph.h"
#include "DAG.h"

#define FILE_PATH "grafo2.txt"

int main(void)
{
    FILE *fp = fopen(FILE_PATH, "r");

    if (fp == NULL)
    {
        printf("\nFile not found.\n");
        return -1;
    }

    Graph g = Graph_load(fp);

    int n;
    subset_t *subsets = Graph_subset_2_create_DAG(g, &n);
    
    Graph_print_subset(subsets, n);

    printf("\n\n");

    DAG d = DAG_create_from_graph(g, subsets, n);

    DAG_cal_max_distance(d);

    Graph_free(g);
    Graph_free_subsets(subsets, n);
    DAG_free(d);
    fclose(fp);
    return 0;
}