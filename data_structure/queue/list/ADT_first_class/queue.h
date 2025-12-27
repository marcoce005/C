#ifndef _QUEUE
#define _QUEUE

typedef int item;

typedef struct queue_s *queue;

/**
 * @brief
 * initialize queue
 * @param maxN
 * with the list it's not necessary
 * @return the queue pointer
 */
queue queue_init(int maxN);

/// @brief free the queue
/// @param q pointer to queue
void queue_free(queue q);

/// @return queue state [boolen value]
/// @param q pointer to queue
int queue_empty(queue q);

/// @brief not necessary with list
/// @return queue state [boolen value]
/// @param q pointer to queue
int queue_full(queue q);

/// @brief Insert element into the queue
/// @param q pointer to queue
/// @param val
void queue_put(queue q, item val);

/// @brief get the first element in the queue
/// @return the extracted item
/// @param q pointer to queue
item queue_get(queue q);

/// @brief print all the elements in the queue
/// @param q pointer to queue.
/// @param prefix String print before item.
/// @param suffix String print after item.
/// @param end String print at the end of the stack.
void queue_print(queue q, char *prefix, char *suffix, char *end);

#endif