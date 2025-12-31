#include <stdlib.h>
#include <string.h>

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

static int compare_computer_id(graph_t g, void *a, void *b) { return strcmp((*(computer_t *)a).id, (*(computer_t *)b).id); }

static int compare_edge_id(graph_t g, void *a, void *b)
{
    char *x = strdup((ST_search_by_index(g->tab, (*((edge_t *)a)).w)).id),
         *y = strdup((ST_search_by_index(g->tab, (*((edge_t *)b)).w)).id);
    int ans = strcmp(x, y);

    free(x);
    free(y);
    return ans;
}

static void merge(void *v, void *b, int l, int r, int m, size_t size, int (*compare)(graph_t, void *, void *), graph_t g)
{
    int i, j, k;
    for (i = k = l, j = m + 1; k <= r; k++)
    {
        if (i > m)
            memcpy(b + k * size, v + (j++ * size), size);
        else if (j > r)
            memcpy(b + k * size, v + (i++ * size), size);
        else if (compare(g, v + i * size, v + j * size) <= 0)
            memcpy(b + k * size, v + (i++ * size), size);
        else
            memcpy(b + k * size, v + (j++ * size), size);
    }
    for (k = l; k <= r; k++)
        memcpy(v + k * size, b + k * size, size);
}

static void merge_sort_r(void *v, void *b, int l, int r, size_t size, int (*compare)(graph_t, void *, void *), graph_t g)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;
    merge_sort_r(v, b, l, m, size, compare, g);
    merge_sort_r(v, b, m + 1, r, size, compare, g);
    merge(v, b, l, r, m, size, compare, g);
}

static void merge_sort(void *v, int n, size_t size, int (*compare)(graph_t, void *, void *), graph_t g)
{
    void *b = (void *)malloc(n * size);
    merge_sort_r(v, b, 0, n - 1, size, compare, g);
    free(b);
}

static edge_t *get_edges(int **m, int r, int c, int vertex, int *n_edges)
{
    int i;
    edge_t *v = (edge_t *)malloc(c * sizeof(edge_t));

    for (i = 0, *n_edges = 0; i < c; i++)
        if (m[vertex][i] != VOID_WEIGHT)
            v[(*n_edges)++] = Edge_create(vertex, i, m[vertex][i]);
    return v;
}

void Graph_print_vertex(graph_t g)
{
    int i, j, n_edges;
    computer_t vertex[g->V];
    edge_t *edges;

    for (i = 0; i < g->V; vertex[i] = ST_search_by_index(g->tab, i), i++) // fill with vertex
        ;
    merge_sort(vertex, g->V, sizeof(vertex[0]), compare_computer_id, g);

    printf("%10s [%s]\t-->\t%s\n\n", "ID", "Net", "Edges spec. with weight");
    for (i = 0; i < g->V; i++)
    {
        printf("%10s [%s]\t-->\t", vertex[i].id, vertex[i].net);

        edges = get_edges(g->mat_adj, g->V, g->V, ST_search_by_computer_id(g->tab, vertex[i].id), &n_edges);
        merge_sort(edges, n_edges, sizeof(edges[0]), compare_edge_id, g);

        for (j = 0; j < n_edges; j++)
            printf("%10s [%s](%3d)\t", ST_search_by_index(g->tab, edges[j].w).id, ST_search_by_index(g->tab, edges[j].w).net, edges[j].wt);
        printf("\n");

        free(edges);
    }
}

static int are_connected_with_matrix(graph_t g, int v, int w)
{
    if (v == -1 || w == -1)
        return 0;
    return g->mat_adj[v][w] != VOID_WEIGHT;
}

static int search_in_list(link h, int k)
{
    if (h == NULL)
        return 0;
    if (h->v == k)
        return 1;
    return search_in_list(h->next, k);
}

static int are_connected_with_list(graph_t g, int v, int w) { return search_in_list(g->vet_lists[v], w); }

static int check_sub_graph(graph_t g, char **vertices, int n, int (*are_connected)(graph_t, int, int))
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (!are_connected(g, ST_search_by_computer_id(g->tab, vertices[i]), ST_search_by_computer_id(g->tab, vertices[j])))
                return 0;
    return 1;
}

void Graph_check_adjacency_beetwen_3_vertex(graph_t g)
{
    int type, ans, n_vertex = 3;
    char buf[128],
        **vertices = (char **)malloc(n_vertex * sizeof(char *));

    printf("\nSelected the method:\n - 0 [using matrix]\n - 1 [using list]\n--> ");
    scanf("%d", &type);

    if (type && g->vet_lists == NULL)
    {
        printf("\nYou have to create list before use it.\n");
        return;
    }

    printf("\nInsert the vertex IDs:\n");
    for (int i = 0; i < n_vertex; i++)
    {
        printf("--> ");
        scanf("%s", buf);
        vertices[i] = strdup(buf);
    }

    ans = check_sub_graph(g, vertices, 3, type ? are_connected_with_list : are_connected_with_matrix);

    if (ans)
        printf("\nExist a sub-graph.\n");
    else
        printf("\nNot exist a sub-graph.\n");

    for (int i = 0; i < n_vertex; i++)
        free(vertices[i]);
    free(vertices);
}