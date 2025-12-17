#include <stdlib.h>

#include "Graph.h"

#define DEFAULT_WEIGHT 0

struct graph
{
    int V, E,
        **mat_adj;
    char *tab;
};

static int **init_matrix_adj(int r, int c)
{
    int i, j,
        **m = (int **)malloc(r * sizeof(int *));

    for (i = 0; i < r; i++)
    {
        m[i] = (int *)malloc(c * sizeof(int));
        for (j = 0; j < c; m[i][j] = DEFAULT_WEIGHT, j++)
            ;
    }
    return m;
}

Graph Graph_init(int V)
{
    Graph g = (Graph)malloc(sizeof(*g));
    g->E = 0;
    g->V = V;
    g->mat_adj = init_matrix_adj(V, V);
    g->tab = NULL;
    return g;
}

Graph Graph_load(FILE *fp_in)
{
    int v;
    fscanf(fp_in, "%d", &v);

    Graph g = Graph_init(v);

    g->tab = (char *)malloc(g->V * sizeof(char));
    for (int i = 0; i < g->V; i++)
        fscanf(fp_in, "%c ", &g->tab[i]);

    // continue

    return g;
}