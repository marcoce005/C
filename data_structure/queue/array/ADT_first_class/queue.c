#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct queue_s
{
    item *q;
    int head, tail, N;
};

static item void_item = -1;

queue queue_init(int size)
{
    if (size <= 0)
    {
        printf("\nInvalid queue size.\n");
        return NULL;
    }
    queue q = (queue)malloc(sizeof(*q));
    q->q = (item *)malloc((size + 1) * sizeof(item));
    q->head = q->N = size + 1;
    q->tail = 0;
    return q;
}

void queue_free(queue q)
{
    if (q == NULL)
    {
        printf("\nFree error: you have to initialize the queue before free it.\n");
        return;
    }
    free(q->q);
    free(q);
}

int queue_empty(queue q) { return q->head % q->N == q->tail; }

int queue_full(queue q) { return (q->tail + 1) % q->N == q->head % q->N; }

void queue_put(queue q, item val)
{
    if (q == NULL)
    {
        printf("\nqueue error: queue have to be initialized if you want to push an item.\n");
        return;
    }
    if (queue_full(q))
    {
        printf("\nPut error: queue is full.\n");
        return;
    }
    q->q[q->tail++] = val;
    q->tail %= q->N;
}

item queue_get(queue q)
{
    if (q == NULL)
    {
        printf("\nqueue error: queue have to be initialized if you want to pop an item.\n");
        return void_item;
    }
    if (queue_empty(q))
    {
        printf("\nGet error: queue is empty.\n");
        return void_item;
    }
    q->head %= q->N;
    return q->q[q->head++];
}

void queue_print(queue q, char *prefix, char *suffix, char *end)
{
    if (q == NULL)
    {
        printf("\nqueue error: queue have to be initialized if you want to print it.\n");
        return;
    }
    for (int i = q->head % q->N; i != q->tail; i++, i %= q->N)
        printf("%s%d%s", prefix, q->q[i], suffix);
    printf("%s", end);
}