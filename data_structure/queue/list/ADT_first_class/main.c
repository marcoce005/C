#include <stdio.h>

#include "queue.h"

int main(void)
{
    // try to free the queue before have created it
    queue_free(NULL);

    // create a queue of 5 elements
    queue q = queue_init(5);

    // try to create another stakc
    queue q1 = queue_init(3);

    // check the initial queue of the queue
    printf("\nqueue is empty?\t%s", queue_empty(q) ? "True" : "False");
    printf("\nqueue is full?\t%s\n", queue_full(q) ? "True" : "False");

    for (int i = 0; i < 5; i++)
        queue_put(q, i);

    printf("\nqueue status:\t");
    queue_print(q, "", "\t", "\n");

    // try to push another item
    queue_put(q, 69);

    printf("\nqueue is empty?\t%s", queue_empty(q) ? "True" : "False");
    printf("\nqueue is full?\t%s\n", queue_full(q) ? "True" : "False");

    printf("\n");
    for (int i = 0; i < 5; i++)
        printf("remove:\t%d\n", queue_get(q));

    printf("\nqueue status:\t");
    queue_print(q, "", "\t", "\n");

    printf("\nqueue is empty?\t%s", queue_empty(q) ? "True" : "False");
    printf("\nqueue is full?\t%s\n", queue_full(q) ? "True" : "False");

    // try to remove another item
    queue_get(q);

    queue_free(q);
    queue_free(q1);
    return 0;
}