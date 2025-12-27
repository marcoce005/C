#ifndef _QUEUE
#define _QUEUE

typedef int item;

typedef struct queue_s *queue;

/**
 * @brief Initialize queue.
 *
 * You can only initilize one queue at the time.
 *
 * @param n_max
 * Maximum number of elements in the queue.
 * @return queue pointer
 */
queue queue_init(int n_max);

/// @brief Free the queue.
/// @param q queue pointer
void queue_free(queue q);

/**
 * @brief Check if queue is empty.
 * @param q queue pointer
 * @return
 * - `1` --> empty
 *
 * - `0` --> not empty
 */
int queue_empty(queue q);

/**
 * @brief
 * Check if queue is full.
 * @param q queue pointer
 * @return
 * - `1`--> full
 *
 * - `0` --> not full
 */
int queue_full(queue q);

/**
 * @brief Insert item in the queue.
 * @param q queue pointer
 * @param val
 * Item you want insert
 */
void queue_put(queue q, item val);

/**
 * @brief Extract item in the queue.
 * @param q queue pointer
 * @return item
 * if it's `-1` the pop wasn't done becuase there is a `queue error` or a `Pop error`.
 */
item queue_get(queue q);

/**
 * @brief Print all elements in the queue.
 * @param q queue pointer
 * @param prefix String print before item.
 * @param suffix String print after item.
 * @param end String print at the end of the queue.
 */
void queue_print(queue q, char *prefix, char *suffix, char *end);

#endif