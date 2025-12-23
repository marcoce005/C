#include <stdio.h>

#include "stack.h"

// with array I can use only 1 stack in all the program.

int main(void)
{
    // try to free the stack before have created it
    stack_free(NULL);

    // create a stack of 5 elements
    stack s = stack_init(5);

    // try to create another stakc
    stack s1 = stack_init(3);

    // check the initial stack of the stack
    printf("\nStack is empty?\t%s", stack_empty(s) ? "True" : "False");
    printf("\nStack is full?\t%s\n", stack_full(s) ? "True" : "False");

    for (int i = 0; i < 5; i++)
        stack_push(s, i);

    printf("\nStack status:\t");
    print_stack(s, "", "\t", "\n");

    // try to push another item
    stack_push(s, 69);

    printf("\nStack is empty?\t%s", stack_empty(s) ? "True" : "False");
    printf("\nStack is full?\t%s\n", stack_full(s) ? "True" : "False");

    printf("\n");
    for (int i = 0; i < 5; i++)
        printf("remove:\t%d\n", stack_pop(s));

    printf("\nStack status:\t");
    print_stack(s, "", "\t", "\n");

    printf("\nStack is empty?\t%s", stack_empty(s) ? "True" : "False");
    printf("\nStack is full?\t%s\n", stack_full(s) ? "True" : "False");

    // try to remove another item
    stack_pop(s);

    stack_free(s);
    stack_free(s1);
    return 0;
}