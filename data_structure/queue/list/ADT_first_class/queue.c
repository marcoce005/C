#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

typedef struct node *link;
struct node
{
    item val;
    link next;
};

struct queue_s
{
    link head, tail;
};

static item item_null = -1;

queue queue_init(int maxN)
{
    queue q = (queue)malloc(sizeof(*q));
    q->head = q->tail = NULL;
    return q;
}

static void free_list(link h)
{
    if (h == NULL)
        return;
    free_list(h->next);
    free(h);
}

void queue_free(queue q)
{
    if (q == NULL)
    {
        printf("\nFree error: you have to initialize the queue before free it.\n");
        return;
    }
    free_list(q->head);
    free(q);
}

int queue_empty(queue q) { return q->head == NULL; }

int queue_full(queue q) { return 0; }

static link new_node(item val, link next)
{
    link x = (link)malloc(sizeof(*x));
    x->val = val;
    x->next = next;
    return x;
}

void queue_put(queue q, item val)
{
    if (q == NULL)
    {
        printf("\nQueue error: you have to initialize the queue before use it.\n");
        return;
    }

    if (q->head == NULL)
    {
        q->head = q->tail = new_node(val, q->head);
        return;
    }
    q->tail->next = new_node(val, q->tail->next);
    q->tail = q->tail->next;
}

item queue_get(queue q)
{
    if (q == NULL)
    {
        printf("\nQueue error: you have to initialize the queue before use it.\n");
        return item_null;
    }
    if (queue_empty(q))
    {
        printf("\nQueue error: queue is empty you can't get item.\n");
        return item_null;
    }
    link t = q->head;
    item val = q->head->val;
    q->head = q->head->next;
    free(t);
    return val;
}

static void print_list(link h, char *pre, char *suf)
{
    if (h == NULL)
        return;
    printf("%s%d%s", pre, h->val, suf);
    print_list(h->next, pre, suf);
}

void queue_print(queue q, char *prefix, char *suffix, char *end)
{
    if (q == NULL)
    {
        printf("\nQueue error: you have to initialize the queue before use it.\n");
        return;
    }
    print_list(q->head, prefix, suffix);
    printf("%s", end);
}