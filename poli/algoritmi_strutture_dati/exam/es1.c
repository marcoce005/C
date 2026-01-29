#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_ST_SIZE 10

typedef struct
{
    char **v;
    int n, n_max;
} *ST;

typedef struct node
{
    char *val;
    struct node *next;
} *link;

link newNode(char *val, link next);
link removeDupl(link h);
void printList(link h);
void freeList(link h);
ST STinit();
int STgetIndexByKey(ST tab, char *k);
void STinsert(ST tab, char *k);
void STfree(ST tab);

int main(void)
{
    link h = NULL;

    h = newNode(strdup("Palermo"), h);
    h = newNode(strdup("Roma"), h);
    h = newNode(strdup("Genova"), h);
    h = newNode(strdup("Torino"), h);
    h = newNode(strdup("Roma"), h);
    h = newNode(strdup("Palermo"), h);
    h = newNode(strdup("Milano"), h);
    h = newNode(strdup("Roma"), h);

    printf("Lista originale:\n");
    printList(h);

    h = removeDupl(h);

    printf("\nLista senza duplicati:\n");
    printList(h);

    freeList(h);
    return 0;
}

link node_rm(link p, link x)
{
    p->next = x->next;
    free(x->val);
    free(x);
    return p;
}

link removeDupl(link h) // errore di battitura nel nome della funzione
{
    ST tab = STinit(); // tabella di simboli avene come chiave di ricerca un puntatore a char
    link x, p;
    for (x = h, p = NULL; x != NULL; p = x, x = x->next)
    {
        if (STgetIndexByKey(tab, x->val) == -1)
        {
            STinsert(tab, x->val); // non presente nella tabella di simboli
        }
        else
        {
            x = node_rm(p, x); // p non verra' mai passato NULL in quanto il primo elemento della listasara' per forza inserito nella tabella di simboli
        }
    }
    STfree(tab); // mancanza della funzione per liberare la tabella di simboli
    return h;    // la testa non verrà mai cambiata, se ci fossero duplicati della testa la prima istanza da mantenere e' proprio la testa quindi essa non cambia mai
}

void STfree(ST tab)
{
    free(tab->v);
    free(tab);
}

void STinsert(ST tab, char *k)
{
    if (tab->n >= tab->n_max)
    {
        tab->n_max *= 2;
        tab->v = realloc(tab->v, tab->n_max * sizeof(char *));
    }
    tab->v[(tab->n)++] = k;
}

int STgetIndexByKey(ST tab, char *k)
{
    for (int i = 0; i < tab->n; i++)
        if (strcmp(k, tab->v[i]) == 0)
            return i;
    return -1;
}

ST STinit()
{
    ST x = malloc(sizeof(*x));
    x->n_max = DEFAULT_ST_SIZE;
    x->n = 0;
    x->v = (char **)malloc(x->n_max * sizeof(char *));
    return x;
}

link newNode(char *val, link next)
{
    link x = malloc(sizeof(*x));
    if (x == NULL)
        return NULL;
    x->val = val;
    x->next = next;
    return x;
}

void printList(link h)
{
    for (; h != NULL; h = h->next)
        printf("-> \"%s\" ", h->val);
    printf("\n");
}

void freeList(link h)
{
    link t;
    while (h != NULL)
    {
        t = h;
        h = h->next;
        free(t->val);
        free(t);
    }
}