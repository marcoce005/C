#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct node *link;
struct node
{
    item val;
    link next;
};

struct stack_s
{
    link head;
};

static item void_item = -1;

stack stack_init(int n_max)
{
    stack s = (stack)malloc(sizeof(*s));
    s->head = NULL;
    return s;
}

static void free_list(link h)
{
    if (h == NULL)
        return;
    free_list(h->next);
    free(h);
}

void stack_free(stack s)
{
    if (s == NULL)
    {
        printf("\nFree error: you have to initialize the stack before free it.\n");
        return;
    }
    free_list(s->head);
    free(s);
}

int stack_empty(stack s)
{
    if (s == NULL)
    {
        printf("\nStack error: you have to initialize the stack before use it.\n");
        return 0;
    }
    return s->head == NULL;
}

int stack_full(stack s) { return 0; }

static link new_node(item val, link next)
{
    link x = (link)malloc(sizeof(*x));
    x->val = val;
    x->next = next;
    return x;
}

void stack_push(stack s, item val)
{
    if (s == NULL)
    {
        printf("\nStack error: you have to initialize the stack before use it.\n");
        return;
    }
    s->head = new_node(val, s->head);
}

item stack_pop(stack s)
{
    if (stack_empty(s))
    {
        printf("\nStack error: stack have to be initialized if you want to pop an item.\n");
        return void_item;
    }

    item tmp = s->head->val;
    link x = s->head;
    s->head = s->head->next;
    free(x);
    return tmp;
}

static void print_list(link h, char *pre, char *suf)
{
    if (h == NULL)
        return;
    printf("%s%d%s", pre, h->val, suf);
    print_list(h->next, pre, suf);
}

void print_stack(stack s, char *prefix, char *suffix, char *end)
{
    if (s == NULL)
    {
        printf("\nStack error: you have to initialize the stack before use it.\n");
        return;
    }
    print_list(s->head, prefix, suffix);
    printf("%s", end);
}