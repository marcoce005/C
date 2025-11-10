#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static item void_item = -1;

struct stack
{
    item *stack;
    int N, max_N;
};

Stack stack_init(int size)
{
    if (size <= 0)
    {
        printf("\nInvalid stack size.\n");
        return NULL;
    }

    Stack sp = (Stack)malloc(sizeof(Stack));
    sp->stack = (item *)malloc(size * sizeof(item));
    sp->N = 0;
    sp->max_N = size;

    return sp;
}

void stack_free(Stack sp)
{
    if (sp == NULL)
    {
        printf("\nFree error: you have to initialize the stack before free it.\n");
        return;
    }

    free(sp->stack);
    free(sp);
}

int stack_empty(Stack sp) { return sp->N == 0; }

int stack_full(Stack sp) { return sp->N == sp->max_N; }

void stack_push(Stack sp, item val)
{
    if (sp->stack == NULL)
    {
        printf("\nStack error: stack have to be initialized if you want to push an item.\n");
        return;
    }

    if (stack_full(sp))
    {
        printf("\nPush error: stack is full.\n");
        return;
    }

    sp->stack[sp->N++] = val;
}

item stack_pop(Stack sp)
{
    if (sp->stack == NULL)
    {
        printf("\nStack error: stack have to be initialized if you want to pop an item.\n");
        return void_item;
    }

    if (stack_empty(sp))
    {
        printf("\nPop error: stack is empty.\n");
        return void_item;
    }

    return sp->stack[--(sp->N)];
}

void print_stack(Stack sp, char *prefix, char *suffix, char *end)
{
    if (sp->stack == NULL)
    {
        printf("\nStack error: stack have to be initialized if you want to print it.\n");
        return;
    }

    for (int i = sp->N - 1; i >= 0; i--)
        printf("%s%d%s", prefix, sp->stack[i], suffix);
    printf("%s", end);
}