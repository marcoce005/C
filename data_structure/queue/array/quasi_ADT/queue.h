#ifndef _QUEUE
#define _QUEUE

typedef int item;

/**
 * @brief Initialize queue.
 *
 * You can only initilize one queue at the time.
 *
 * @param n_max
 * Maximum number of elements in the queue.
 */
void queue_init(int n_max);

/// @brief Free the queue.
void queue_free(void);

/**
 * @brief
 * Check if queue is empty.
 * @return
 * - `1` --> empty
 *
 * - `0` --> not empty
 */
int queue_empty(void);

/**
 * @brief
 * Check if queue is full.
 * @return
 * - `1`--> full
 *
 * - `0` --> not full
 */
int queue_full(void);

/**
 * @brief Insert item in the queue.
 *
 * @param val
 * Item you want insert
 */
void queue_put(item val);

/**
 * @brief Extract item in the queue.
 *
 * @return item
 * if it's `-1` the pop wasn't done becuase there is a `queue error` or a `Pop error`.
 */
item queue_get(void);

/**
 * @brief Print all elements in the queue.
 *
 * @param prefix String print before item.
 * @param suffix String print after item.
 * @param end String print at the end of the queue.
 */
void queue_print(char *prefix, char *suffix, char *end);

#endif