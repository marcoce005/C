#include <stdio.h>

#define NODES 10
#define FILE_PATH "./input.txt"

void online_connectivity(FILE *in, int id[], int sz[]);
int slow_find(int id[], int v); // return the master of the node

int main(void)
{
    FILE *in;
    int id[NODES], sizes[NODES]; // the store also the size of each tree

    for (int i = 0; i < NODES; i++) // init set [the master of the node at start is it self]
    {
        id[i] = i;
        sizes[i] = 1;
    }

    in = fopen(FILE_PATH, "r");

    online_connectivity(in, id, sizes);

    fclose(in);

    return 0;
}

int slow_find(int id[], int v)
{
    int i;
    for (i = v; id[i] != i; i = id[i])
        ;
    return i;
}

void online_connectivity(FILE *in, int id[], int sz[])
{
    int p, q, master_p, master_q;
    while (fscanf(in, "%d %d", &p, &q) == 2)
    {
        printf("\n\n%d\t%d\t-->\t", p, q);

        master_p = slow_find(id, p);
        master_q = slow_find(id, q);

        if (master_p != master_q)
        {
            if (sz[master_p] <= sz[master_q]) // if q tree is larger we add p tree to q tree
            {
                id[master_p] = master_q; // quick union
                sz[master_q] += sz[master_p];
            }
            else // else we add q tree to p tree
            {
                id[master_q] = master_p; // quick union
                sz[master_p] += sz[master_q];
            }
        }

        for (int i = 0; i < NODES; i++)
            printf(" %d", id[i]);

        printf("\t|\t");

        for (int i = 0; i < NODES; i++)
            printf(" %d", sz[i]);
    }
}