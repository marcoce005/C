#include <stdio.h>

#include "queue.h"

// I can use only 1 queue in all the program.

int main(void)
{
    // try to free the queue before have created it
    queue_free();

    // create a queue of 5 elements
    queue_init(5);

    // try to create another stakc
    queue_init(3);

    // check the initial queue of the queue
    printf("\nqueue is empty?\t%s", queue_empty() ? "True" : "False");
    printf("\nqueue is full?\t%s\n", queue_full() ? "True" : "False");

    for (int i = 0; i < 5; i++)
        queue_put(i);

    printf("\nqueue status:\t");
    queue_print("", "\t", "\n");

    // try to push another item
    queue_put(69);

    printf("\nqueue is empty?\t%s", queue_empty() ? "True" : "False");
    printf("\nqueue is full?\t%s\n", queue_full() ? "True" : "False");

    printf("\n");
    for (int i = 0; i < 5; i++)
        printf("remove:\t%d\n", queue_get());

    printf("\nqueue status:\t");
    queue_print("", "\t", "\n");

    printf("\nqueue is empty?\t%s", queue_empty() ? "True" : "False");
    printf("\nqueue is full?\t%s\n", queue_full() ? "True" : "False");

    // try to remove another item
    queue_get();

    queue_free();
    queue_free();
    return 0;
}