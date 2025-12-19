#include <stdlib.h>

#include "Graph.h"

#define DEFAULT_WEIGHT 0

struct graph
{
    int V, E,
        **mat_adj;
    // use the corrispondation char --> int for the vertex id [ex. A --> 0, B --> 1, ...]
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

static void free_matrix_adj(int **m, int r) {
    for (int i = 0; i < r; i++)
        free(m[i]);
    free(m);
}

Graph Graph_init(int V)
{
    Graph g = (Graph)malloc(sizeof(*g));
    g->E = 0;
    g->V = V;
    g->mat_adj = init_matrix_adj(V, V);
    return g;
}

void Graph_free(Graph g) {
    free_matrix_adj(g->mat_adj, g->V);
    free(g);
}

static edge_t edge_create(int v, int w, int wt)
{
    edge_t x = {v, w, wt};
    return x;
}

static int index_by_key(char c) { return c - 'A'; }

static char key_by_index(int n) { return n + 'A'; }

static void edge_insert(Graph g, edge_t e)
{
    if (g->mat_adj[e.v][e.w] == DEFAULT_WEIGHT)
        g->E++;
    g->mat_adj[e.v][e.w] = e.wt;
}

Graph Graph_load(FILE *fp_in)
{
    int v, i, wt;
    char a, b;

    fscanf(fp_in, "%d ", &v);

    Graph g = Graph_init(v);

    for (i = 0; i < g->V; fscanf(fp_in, "%*c "), i++)
        ;

    while (fscanf(fp_in, "%c %c %d ", &a, &b, &wt) == 3)
        edge_insert(g, edge_create(index_by_key(a), index_by_key(b), wt));

    return g;
}