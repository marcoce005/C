#ifndef _GRAPH
#define _GRAPH

#include <stdio.h>

typedef struct edge_s
{
    int v, w, wt;
} edge_t;

typedef struct graph_s *graph_t;

graph_t Graph_init(int n_vertex);

void Graph_free(graph_t g);

graph_t Graph_load(FILE *fp_in);

void Graph_insert_edge(graph_t g, int id0, int id1, int wt);

void Graph_create_list_adjacency(graph_t g);

#endif