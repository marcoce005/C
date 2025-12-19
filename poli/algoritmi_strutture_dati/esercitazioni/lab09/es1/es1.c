#include <stdio.h>

#include "Graph.h"
#include "DAG.h"

#define FILE_PATH "grafo1.txt"

int main(void) {
    FILE *fp = fopen(FILE_PATH, "r");

    if (fp == NULL) {
        printf("\nFile not found.\n");
        return -1;
    }

    Graph g = Graph_load(fp);


    Graph_free(g);
    fclose(fp);
    return 0;
}