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

static void print_mat_adj(int **m, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
}

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

static void TS_dfs(DAG d, int v, int *ts, int *pre, int *time)
{
    int w;
    pre[v] = 0;
    for (w = 0; w < d->V; w++)
        if (d->mat_adj[w][v] != DEFAULT_WEIGHT)
            if (pre[w] == -1)
                TS_dfs(d, w, ts, pre, time);
    ts[(*time)++] = v;
}

static int *get_TS(DAG d)
{
    int v, time = 0, *pre, *ts;

    pre = (int *)malloc(d->V * sizeof(int));
    ts = (int *)malloc(d->V * sizeof(int));

    for (v = 0; v < d->V; pre[v] = -1, ts[v] = -1, v++)
        ;

    for (v = 0; v < d->V; v++)
        if (pre[v] == -1)
            TS_dfs(d, v, ts, pre, &time);

    free(pre);
    return ts;
}

static int vertex_is_source(DAG d, int v)
{
    for (int i = 0; i < d->V; i++)
        if (d->mat_adj[i][v] != DEFAULT_WEIGHT)
            return 0;
    return 1;
}

static void print_arr(int *v, int n)
{
    for (int i = 0; i < n; printf("%d ", v[i]), i++)
        ;
}

static int *distance_from_vertex(DAG d, int v, int *top_sort)
{
    int i, j,
        *dist = (int *)malloc(d->V * sizeof(int));

    for (i = 0; i < d->V; dist[i] = -1, i++)
        ;
    dist[v] = 0;

    for (i = 0; i < d->V; i++)
        for (j = i + 1; j < d->V; j++)
            if (d->mat_adj[top_sort[i]][top_sort[j]] != DEFAULT_WEIGHT && dist[top_sort[j]] < dist[top_sort[i]] + d->mat_adj[top_sort[i]][top_sort[j]])
                dist[top_sort[j]] = dist[top_sort[i]] + d->mat_adj[top_sort[i]][top_sort[j]];
    return dist;
}

void DAG_cal_max_distance(DAG d)
{
    int i, j, *distances, *top_sort = get_TS(d);

    for (i = 0; i < d->V; i++)
        if (vertex_is_source(d, top_sort[i]))
        {
            printf("\n%c is a source vertex:\n", key_by_index(top_sort[i]));
            distances = distance_from_vertex(d, top_sort[i], top_sort);

            for (j = 0; j < d->V; j++)
                if (j != top_sort[i])
                    printf("--> %c %d\n", key_by_index(j), distances[j]);

            free(distances);
        }
    free(top_sort);
}