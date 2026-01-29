#include <stdio.h>
#include <stdlib.h>

typedef int Key;

typedef struct node *link;

struct node
{
    Key key;
    link left;
    link right;
};

typedef struct
{
    link root;
    link z;
} *BST;

link NEW(Key key, link l, link r);
BST BSTinit(void);
link insertR(link h, link z, Key k);
void BSTinsert(BST b, Key k);
void search(link h, link z, Key k1, Key k2, int *founded, int *nodes);
int BSTcountBetween(BST b, Key k1, Key k2);
int KeyEqual(Key a, Key b);
int KeyLess(Key a, Key b);

int main(void)
{
    BST b = BSTinit();

    int keys[] = {10, 5, 15, 3, 7, 18};
    int n = sizeof(keys) / sizeof(keys[0]);

    /* BST:
               10
              /  \
             5   15
            / \   \
           3   7   18
   */

    for (int i = 0; i < n; i++)
        BSTinsert(b, keys[i]);

    printf("Test 1 (k1=5, k2=15) -> %d\n",
           BSTcountBetween(b, 5, 15));

    printf("Test 2 (k1=3, k2=18) -> %d\n",
           BSTcountBetween(b, 3, 18));

    printf("Test 3 (k1=5, k2=7) -> %d\n",
           BSTcountBetween(b, 5, 7));

    printf("Test 4 (k1=5, k2=100) -> %d\n",
           BSTcountBetween(b, 5, 100));

    printf("Test 5 (k1=7, k2=5) -> %d\n",
           BSTcountBetween(b, 7, 5));

    return 0;
}

void search(link h, link z, Key k1, Key k2, int *founded, int *nodes)
{
    if (h == z || *founded == 2)
        return;
    search(h->left, z, k1, k2, founded, nodes);
    if (KeyEqual(h->key, k1) || KeyEqual(h->key, k2))
        (*founded)++;
    if (*founded == 1)
        (*nodes)++;
    search(h->right, z, k1, k2, founded, nodes);
}
int BSTcountBetween(BST b, Key k1, Key k2)
{
    int founded, nodes;
    founded = nodes = 0;
    search(b->root, b->z, k1, k2, &founded, &nodes);
    if (founded == 2)
        return nodes - 1; // -1 perche' appena viene trovato il primo esso viene contato
    return -1;
}

int KeyEqual(Key a, Key b) { return a == b; }

int KeyLess(Key a, Key b) { return a < b; }

link NEW(Key key, link l, link r)
{
    link x = malloc(sizeof *x);
    x->key = key;
    x->left = l;
    x->right = r;
    return x;
}

BST BSTinit(void)
{
    BST b = malloc(sizeof(*b));
    b->z = NEW(0, NULL, NULL);
    b->z->left = b->z->right = b->z;
    b->root = b->z;
    return b;
}

link insertR(link h, link z, Key k)
{
    if (h == z)
        return NEW(k, z, z);
    if (KeyLess(k, h->key))
        h->left = insertR(h->left, z, k);
    else
        h->right = insertR(h->right, z, k);
    return h;
}

void BSTinsert(BST b, Key k)
{
    b->root = insertR(b->root, b->z, k);
}