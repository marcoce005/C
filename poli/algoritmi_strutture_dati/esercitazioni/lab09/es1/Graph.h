#ifndef _GRAPH
#define _GRAPH

#include <stdio.h>

typedef struct
{
    int v, w, wt;
} edge_t;

typedef struct 
{
    int n, tot;
    edge_t *edges;
} subset_t;

typedef struct graph *Graph;

Graph Graph_init(int V);

void Graph_free(Graph g);

Graph Graph_load(FILE *fp_in);

edge_t *Graph_edges(Graph g);

subset_t *Graph_subset_2_create_DAG(Graph g, int *n_subsets);

void Graph_print_subset(subset_t *subsets, int n);

void Graph_free_subsets(subset_t *subsets, int n);

#endif