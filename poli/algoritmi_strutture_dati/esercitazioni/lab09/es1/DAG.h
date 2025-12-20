#ifndef _DAG
#define _DAG

#include "Graph.h"

typedef struct dag *DAG;

DAG DAG_init(int v);

void DAG_free(DAG d);

DAG DAG_create_from_graph(Graph g, subset_t *subsets, int n);

#endif