#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

typedef struct node *link;
struct node
{
    item val;
    link next;
};

static link head, tail;

static item item_null = -1;

void queue_init(int maxN) { head = tail = NULL; }

static void free_list(link h)
{
    if (h == NULL)
        return;
    free_list(h->next);
    free(h);
}

void queue_free(void) { free_list(head); }

int queue_empty(void) { return head == NULL; }

int queue_full(void) { return 0; }

static link new_node(item val, link next)
{
    link x = (link)malloc(sizeof(*x));
    x->val = val;
    x->next = next;
    return x;
}

void queue_put(item val)
{
    if (head == NULL)
    {
        head = tail = new_node(val, head);
        return;
    }
    tail->next = new_node(val, tail->next);
    tail = tail->next;
}

item queue_get(void)
{
    if (queue_empty())
    {
        printf("\nQueue error: queue is empty you can't get item.\n");
        return item_null;
    }
    link t = head;
    item val = head->val;
    head = head->next;
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

void queue_print(char *prefix, char *suffix, char *end)
{
    print_list(head, prefix, suffix);
    printf("%s", end);
}
