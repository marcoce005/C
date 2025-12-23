#include <stdio.h>
#include "stack.h"

// with array I can use only 1 stack in all the program.

int main(void)
{
    // try to free the stack before have created it
    stack_free();

    // create a stack of 5 elements
    stack_init(5);

    // try to create another stakc [error]
    stack_init(3);

    // check the initial stack of the stack
    printf("\nStack is empty?\t%s", stack_empty() ? "True" : "False");
    printf("\nStack is full?\t%s\n", stack_full() ? "True" : "False");

    for (int i = 0; i < 5; i++)
        stack_push(i);

    printf("\nStack status:\t");
    print_stack("", "\t", "\n");

    // try to push another item [error]
    stack_push(69);

    printf("\nStack is empty?\t%s", stack_empty() ? "True" : "False");
    printf("\nStack is full?\t%s\n", stack_full() ? "True" : "False");

    printf("\n");
    for (int i = 0; i < 5; i++)
        printf("remove:\t%d\n", stack_pop());

    printf("\nStack status:\t");
    print_stack("", "\t", "\n");

    printf("\nStack is empty?\t%s", stack_empty() ? "True" : "False");
    printf("\nStack is full?\t%s\n", stack_full() ? "True" : "False");

    // try to remove another item [error]
    stack_pop();

    stack_free();
    return 0;
}