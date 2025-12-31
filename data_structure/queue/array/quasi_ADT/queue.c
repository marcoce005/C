#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static item *queue = NULL, void_item = -1;
static int head, tail, N;

void queue_init(int size)
{
    if (queue != NULL)
    {
        printf("\nqueue was already created.\n");
        return;
    }
    if (size <= 0)
    {
        printf("\nInvalid queue size.\n");
        return;
    }
    queue = (item *)malloc((size + 1) * sizeof(item));
    head = N = size + 1;
    tail = 0;
}

void queue_free(void)
{
    if (queue == NULL)
    {
        printf("\nFree error: you have to initialize the queue before free it.\n");
        return;
    }
    free(queue);
    queue = NULL;
}

int queue_empty(void) { return head % N == tail; }

int queue_full(void) { return (tail + 1) % N == head  % N; }

void queue_put(item val)
{
    if (queue == NULL)
    {
        printf("\nqueue error: queue have to be initialized if you want to push an item.\n");
        return;
    }
    if (queue_full())
    {
        printf("\nPut error: queue is full.\n");
        return;
    }
    queue[tail++] = val;
    tail %= N;
}

item queue_get(void)
{
    if (queue == NULL)
    {
        printf("\nqueue error: queue have to be initialized if you want to pop an item.\n");
        return void_item;
    }
    if (queue_empty())
    {
        printf("\nGet error: queue is empty.\n");
        return void_item;
    }
    head %= N;
    return queue[head++];
}

void queue_print(char *prefix, char *suffix, char *end)
{
    if (queue == NULL)
    {
        printf("\nqueue error: queue have to be initialized if you want to print it.\n");
        return;
    }
    for (int i = head % N; i != tail; i++, i %= N)
        printf("%s%d%s", prefix, queue[i], suffix);
    printf("%s", end);
}