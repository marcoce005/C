#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct node *link;
struct node
{
    item val;
    link next;
};

static link head;
static item void_item = -1;

void stack_init(int n_max) { head = NULL; }

static void free_list(link h)
{
    if (h == NULL)
        return;
    free_list(h->next);
    free(h);
}

void stack_free(void) { free_list(head); }

int stack_empty(void) { return head == NULL; }

int stack_full(void) { return 0; }

static link new_node(item val, link next)
{
    link x = (link)malloc(sizeof(*x));
    x->val = val;
    x->next = next;
    return x;
}

void stack_push(item val) { head = new_node(val, head); }

item stack_pop(void)
{
    if (stack_empty())
    {
        printf("\nStack error: stack have to be initialized if you want to pop an item.\n");
        return void_item;
    }

    item tmp = head->val;
    link x = head;
    head = head->next;
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

void print_stack(char *prefix, char *suffix, char *end)
{
    print_list(head, prefix, suffix);
    printf("%s", end);
}