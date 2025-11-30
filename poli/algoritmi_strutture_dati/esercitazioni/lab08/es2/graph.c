#include <stdlib.h>

#include "graph.h"
#include "ST.h"

#define VOID_WEIGHT 0
#define DEFAULT_N_VERTEX 10

typedef struct node_t *link;
struct node_t
{
    int v, wt;
    link next;
};

struct graph_s
{
    int V, max_V, E, **mat_adj;
    ST tab;
    link *vet_lists;
};

static int **init_mat_adj(int r, int c, int default_wt)
{
    int i, j, **mat;
    mat = (int **)malloc(r * sizeof(int *));

    for (i = 0; i < r; i++)
    {
        mat[i] = (int *)malloc(c * sizeof(int));
        for (j = 0; j < c; mat[i][j] = default_wt, j++)
            ;
    }
    return mat;
}

static void free_mat_adj(int ***m, int r, int c)
{
    for (int i = 0; i < r; i++)
        free((*m)[i]);
    free(*m);
}

static void free_list(link h)
{
    if (h == NULL)
        return;
    free_list(h->next);
    free(h);
}

static void free_lists(graph_t g)
{
    for (int i = 0; i < g->V; i++)
        free_list(g->vet_lists[i]);
    free(g->vet_lists);
}

static void realloc_matrix(int ***m, int new_r, int new_c, int old_r, int old_c)
{
    int i, j;
    *m = (int **)realloc(*m, new_r * sizeof(int *));
    for (i = 0; i < new_r; i++)
    {
        if (i < old_r)
        {
            (*m)[i] = (int *)realloc((*m)[i], new_c * sizeof(int));
            j = old_c;
        }
        else
        {
            (*m)[i] = (int *)malloc(new_c * sizeof(int));
            j = 0;
        }
        for (; j < new_c; j++)
            (*m)[i][j] = VOID_WEIGHT;
    }
}

graph_t Graph_init(int n_vertex)
{
    graph_t g = (graph_t)malloc(sizeof(*g));
    g->E = g->V = 0;
    g->max_V = n_vertex;
    g->tab = ST_init(g->max_V);
    g->mat_adj = init_mat_adj(g->max_V, g->max_V, VOID_WEIGHT);
    g->vet_lists = NULL;
    return g;
}

void Graph_free(graph_t g)
{
    ST_free(g->tab);
    free_mat_adj(&(g->mat_adj), g->max_V, g->max_V);
    if (g->vet_lists != NULL)
        free_lists(g);
    free(g);
}

static edge_t Edge_create(int v, int w, int wt)
{
    edge_t x = {v, w, wt};
    return x;
}

// static void print_mat(int **m, int r, int c)
// {
//     int i, j;
//     printf("\t");
//     for (i = 0; i < r; i++)
//         printf("%3d ", i);
//     printf("\n\n");
//     for (i = 0; i < r; i++)
//     {
//         printf("%d\t", i);
//         for (j = 0; j < c; j++)
//             printf("%3d ", m[i][j]);
//         printf("\n");
//     }
// }

// static void print_list(link h)
// {
//     if (h == NULL)
//         return;
//     printf("%d/%d ", h->v, h->wt);
//     print_list(h->next);
// }

// static void print_lists(graph_t g)
// {
//     for (int i = 0; i < g->V; i++)
//     {
//         printf("%d --> ", i);
//         print_list(g->vet_lists[i]);
//         printf("\n");
//     }
// }

static void Edge_insert(graph_t g, edge_t e)
{
    if (g->mat_adj[e.v][e.w] == 0)
    {
        g->E++;
        g->mat_adj[e.v][e.w] = g->mat_adj[e.w][e.v] = e.wt;
    }
}

graph_t Graph_load(FILE *fp_in)
{
    computer_t pc0, pc1;
    int wt, id0, id1;
    graph_t g = Graph_init(DEFAULT_N_VERTEX);

    while (fscanf(fp_in, "%s %s %s %s %d", pc0.id, pc0.net, pc1.id, pc1.net, &wt) == 5)
    {
        id0 = ST_search_by_computer_id(g->tab, pc0.id);
        id1 = ST_search_by_computer_id(g->tab, pc1.id);

        if (id0 < 0)
        {
            id0 = g->V++;
            ST_insert(g->tab, pc0, id0);
        }
        if (id1 < 0)
        {
            id1 = g->V++;
            ST_insert(g->tab, pc1, id1);
        }

        if (g->V > g->max_V) // increase mat_adj size
        {
            g->max_V *= 2;
            realloc_matrix(&(g->mat_adj), g->max_V, g->max_V, g->max_V / 2, g->max_V / 2);
        }
        Graph_insert_edge(g, id0, id1, wt);
    }
    return g;
}

void Graph_insert_edge(graph_t g, int id0, int id1, int wt) { Edge_insert(g, Edge_create(id0, id1, wt)); }

static link new_node(int v, int wt, link next)
{
    link x = (link)malloc(sizeof *x);
    x->v = v;
    x->wt = wt;
    x->next = next;
    return x;
}

static void list_ins_edge(graph_t g, edge_t e)
{
    g->vet_lists[e.v] = new_node(e.w, e.wt, g->vet_lists[e.v]);
    g->vet_lists[e.w] = new_node(e.v, e.wt, g->vet_lists[e.w]);
}

void Graph_create_list_adjacency(graph_t g)
{
    if (g->vet_lists != NULL)
    {
        printf("\nList has already created.\n");
        return;
    }

    int i, j;
    g->vet_lists = (link *)malloc(g->V * sizeof(link));
    for (int i = 0; i < g->V; g->vet_lists[i] = NULL, i++)
        ;

    for (i = 0; i < g->V; i++)
        for (j = i; j < g->V; j++)
            if (g->mat_adj[i][j] != VOID_WEIGHT)
                list_ins_edge(g, Edge_create(i, j, g->mat_adj[i][j]));
}