#ifndef _GRAPH
#define _GRAPH

#include <stdio.h>

typedef struct
{
    int v, w, wt;
} edge_t;

typedef struct graph *Graph;

Graph Graph_init(int V);

void Graph_free(Graph g);

Graph Graph_load(FILE *fp_in);

#endif