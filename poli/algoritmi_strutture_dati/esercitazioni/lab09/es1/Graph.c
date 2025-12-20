#include <stdlib.h>
#include <string.h>

#include "Graph.h"

#define DEFAULT_WEIGHT 0

typedef struct node_s *link;
typedef struct node_s
{
    int v, wt, disable;
    link next;
} node_t;

struct graph
{
    int V, E;
    link *list_adj;
    // use the corrispondation char --> int for the vertex id [ex. A --> 0, B --> 1, ...]
};

static link *init_arr_list(int v)
{
    link *arr = (link *)malloc(v * sizeof(link));
    for (int i = 0; i < v; arr[i] = NULL, i++)
        ;
    return arr;
}

Graph Graph_init(int V)
{
    Graph g = (Graph)malloc(sizeof(*g));
    g->E = 0;
    g->V = V;
    g->list_adj = init_arr_list(V);
    return g;
}

static void free_list(link h)
{
    if (h == NULL)
        return;
    free_list(h->next);
    free(h);
}

void Graph_free(Graph g)
{
    for (int i = 0; i < g->V; free_list(g->list_adj[i]), i++)
        ;
    free(g->list_adj);
    free(g);
}

static edge_t edge_create(int v, int w, int wt)
{
    edge_t x = {v, w, wt};
    return x;
}

static int index_by_key(char c) { return c - 'A'; }

static char key_by_index(int n) { return n + 'A'; }

static link new_node(int v, int wt, link next)
{
    link x = (link)malloc(sizeof(*x));
    x->v = v;
    x->wt = wt;
    x->disable = 0;
    x->next = next;
    return x;
}

static void edge_insert(Graph g, edge_t e)
{
    g->list_adj[e.v] = new_node(e.w, e.wt, g->list_adj[e.v]);
    g->E++;
}

// static void print_list(link h) {
//     if (h == NULL)
//         return;
//     printf("%c ", key_by_index(h->v));
//     print_list(h->next);
// }

// static void print_list_adj(Graph g) {
//     for (int i = 0; i < g->V; i++) {
//         printf("%c --> ", key_by_index(i));
//         print_list(g->list_adj[i]);
//         printf("\n");
//     }
// }

static void print_edges(edge_t *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%c %c %d\n", key_by_index(arr[i].v), key_by_index(arr[i].w), arr[i].wt);
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

edge_t *Graph_edges(Graph g)
{
    edge_t *arr = (edge_t *)malloc(g->E * sizeof(edge_t));
    for (int i = 0, index = 0; i < g->V; i++)
    {
        if (g->list_adj[i] != NULL)
            for (link x = g->list_adj[i]; x != NULL; x = x->next)
                arr[index++] = edge_create(i, x->v, x->wt);
    }
    return arr;
}

static int dfs_r(Graph g, int v, int *pre, int *post)
{
    pre[v] = 1;
    for (link t = g->list_adj[v]; t != NULL; t = t->next)
    {
        if (!(t->disable))
        {
            if (pre[t->v] == -1)
            {
                if (dfs_r(g, t->v, pre, post))
                    return 1;
            }
            else if (post[t->v] == -1)
                return 1;
        }
    }
    post[v] = 1;
    return 0;
}

static int there_is_cycle(Graph g)
{
    int i, *pre, *post;

    pre = (int *)malloc(g->V * sizeof(int));
    post = (int *)malloc(g->V * sizeof(int));

    for (i = 0; i < g->V; pre[i] = post[i] = -1, i++)
        ;

    for (i = 0; i < g->V; i++)
        if (pre[i] == -1 && dfs_r(g, i, pre, post))
        {
            free(pre);
            free(post);
            return 1;
        }

    free(pre);
    free(post);
    return 0;
}

static void comb(int pos, int start, int n, int k, int *sol, int *val, int **sols, int *index)
{
    if (pos >= k)
    {
        memcpy(sols[(*index)++], sol, k * sizeof(int));
        return;
    }

    for (int i = start; i < n; i++)
    {
        sol[pos] = val[i];
        comb(pos + 1, i + 1, n, k, sol, val, sols, index);
    }
}

static double fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

static void free_matrix(int **m, int r)
{
    for (int i = 0; i < r; i++)
        free(m[i]);
    free(m);
}

static void change_edge_status(Graph g, edge_t x, int status)
{
    link t;
    for (t = g->list_adj[x.v]; t->v != x.w; t = t->next)
        ;
    t->disable = status;
}

static void filter_valid_subset(Graph g, edge_t *edges, int **subset, int n_sub, int k, int **filtered, int *n_valid)
{
    int i, j;
    for (i = 0; i < n_sub; i++)
    {
        // disable edges
        for (j = 0; j < k; change_edge_status(g, edges[subset[i][j]], 1), j++)
            ;

        if (!there_is_cycle(g))
            memcpy(filtered[(*n_valid)++], subset[i], k * sizeof(int));

        // enable edges for the next subset
        for (j = 0; j < k; change_edge_status(g, edges[subset[i][j]], 0), j++)
            ;
    }
}

static subset_t fill_subset(edge_t *edges, int *v, int n)
{
    int i, tot;
    edge_t *arr = (edge_t *)malloc(n * sizeof(edge_t));
    for (i = tot = 0; i < n; i++)
    {
        tot += edges[v[i]].wt;
        arr[i] = edges[v[i]];
    }
    subset_t s = {n, tot, arr};
    return s;
}

subset_t *Graph_subset_2_create_DAG(Graph g, int *n_subsets)
{
    if (!there_is_cycle(g))
    {
        *n_subsets = 0;
        return NULL;
    }

    edge_t *edges = Graph_edges(g);
    int i, k, val[g->E], *sol, **subset, **valid_sub, n_sols, index;

    for (int i = 0; i < g->E; val[i] = i, i++)
        ;

    for (k = 1; k < g->E; k++)
    {
        index = *n_subsets = 0;
        sol = (int *)malloc(k * sizeof(int));
        n_sols = (int)(fact(g->E) / (fact(k) * fact(g->E - k)));

        subset = (int **)malloc(n_sols * sizeof(int *));
        valid_sub = (int **)malloc(n_sols * sizeof(int *));
        for (i = 0; i < n_sols; i++)
        {
            subset[i] = (int *)malloc(k * sizeof(int));
            valid_sub[i] = (int *)malloc(k * sizeof(int));
        }

        comb(0, 0, g->E, k, sol, val, subset, &index);

        filter_valid_subset(g, edges, subset, n_sols, k, valid_sub, n_subsets);

        free(sol);
        free_matrix(subset, n_sols);

        if (*n_subsets != 0)
            break;
        else
            free_matrix(valid_sub, n_sols);
    }

    subset_t *ans = (subset_t *)malloc(*n_subsets * sizeof(subset_t));
    for (i = 0; i < *n_subsets; i++)
        ans[i] = fill_subset(edges, valid_sub[i], k);

    free_matrix(valid_sub, n_sols);
    return ans;
}

void Graph_print_subset(subset_t *subsets, int n)
{
    if (n == 0 && subsets == NULL)
        printf("\nThe Graph is already a DAG.\n");

    printf("\nSubsets that made the graph a DAG:");
    for (int i = 0; i < n; i++)
    {
        printf("\nSubset #%d\nTot --> %d\nDisabled edges:\n", i + 1, subsets[i].tot);
        print_edges(subsets[i].edges, subsets[i].n);
    }
}

void Graph_free_subsets(subset_t *subsets, int n)
{
    for (int i = 0; i < n; i++)
        free(subsets[i].edges);
    free(subsets);
}