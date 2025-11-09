#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static item *stack = NULL, void_item = -1;
static int N, max_N;

void stack_init(int size)
{
    if (stack != NULL)
    {
        printf("\nStack was already created.\n");
        return;
    }

    if (size <= 0)
    {
        printf("\nInvalid stack size.\n");
        return;
    }

    stack = (item *)malloc(size * sizeof(item));
    N = 0;
    max_N = size;
}

void stack_free(void)
{
    if (stack == NULL)
    {
        printf("\nFree error: you have to initialize the stack before free it.\n");
        return;
    }

    free(stack);
    stack = NULL;
}

int stack_empty(void) { return N == 0; }

int stack_full(void) { return N == max_N; }

void stack_push(item val)
{
    if (stack == NULL)
    {
        printf("\nStack error: stack have to be initialized if you want to push an item.\n");
        return;
    }

    if (stack_full())
    {
        printf("\nPush error: stack is full.\n");
        return;
    }

    stack[N++] = val;
}

item stack_pop(void)
{
    if (stack == NULL)
    {
        printf("\nStack error: stack have to be initialized if you want to pop an item.\n");
        return void_item;
    }

    if (stack_empty())
    {
        printf("\nPop error: stack is empty.\n");
        return void_item;
    }

    return stack[--N];
}

void print_stack(char *prefix, char *suffix, char *end)
{
    if (stack == NULL)
    {
        printf("\nStack error: stack have to be initialized if you want to print it.\n");
        return;
    }

    for (int i = N - 1; i >= 0; i--)
        printf("%s%d%s", prefix, stack[i], suffix);
    printf("%s", end);
}