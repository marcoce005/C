#include <stdlib.h>

#include "DAG.h"

#define DEFAULT_WEIGHT 0

struct dag
{
    int V, E, **mat_adj;
};

static int **init_mat_adj(int r, int c)
{
    int i, j, **m = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
    {
        m[i] = (int *)malloc(c * sizeof(int));
        for (j = 0; j < c; m[i][j] = DEFAULT_WEIGHT, j++)
            ;
    }
    return m;
}

DAG DAG_init(int v)
{
    DAG d = (DAG)malloc(sizeof(*d));
    d->V = v;
    d->E = 0;
    d->mat_adj = init_mat_adj(v, v);
    return d;
}

static void free_matrix(int **m, int r)
{
    for (int i = 0; i < r; i++)
        free(m[i]);
    free(m);
}

void DAG_free(DAG d)
{
    free_matrix(d->mat_adj, d->V);
    free(d);
}

static int index_by_key(char c) { return c - 'A'; }

static char key_by_index(int n) { return n + 'A'; }

static void edge_insert(DAG d, edge_t e) { d->mat_adj[e.v][e.w] = e.wt; }

static void edge_remove(DAG d, edge_t e)
{
    if (d->mat_adj[e.v][e.w] != DEFAULT_WEIGHT)
        d->E--;
    d->mat_adj[e.v][e.w] = DEFAULT_WEIGHT;
}

static void copy_graph(DAG d, edge_t *edges)
{
    for (int i = 0; i < d->E; edge_insert(d, edges[i]), i++)
        ;
}

static int index_max_tot(subset_t *subsets, int n)
{
    int i, max;
    for (i = max = 0; i < n; i++)
        if (subsets[i].tot > subsets[max].tot)
            max = i;
    return max;
}

// static void print_mat_adj(int **m, int r, int c)
// {
//     int i, j;
//     for (i = 0; i < r; i++)
//     {
//         for (j = 0; j < c; j++)
//             printf("%3d ", m[i][j]);
//         printf("\n");
//     }
// }

DAG DAG_create_from_graph(Graph g, subset_t *subsets, int n)
{
    DAG d = DAG_init(Graph_n_vertices(g));
    copy_graph(d, Graph_edges(g, &(d->E)));

    if (n != 0 && subsets != NULL)
    {
        int index_max = index_max_tot(subsets, n);
        for (int i = 0; i < subsets[index_max].n; i++)
            edge_remove(d, subsets[index_max].edges[i]);
    }
    return d;
}