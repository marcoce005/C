#ifndef _QUEUE
#define _QUEUE

typedef int item;

/**
 * @brief 
 * initialize queue
 * @param maxN 
 * with the list it's not necessary
 */
void queue_init(int maxN);

/// @brief free the queue 
void queue_free(void);

/// @return queue state [boolen value] 
int queue_empty(void);

/// @brief not necessary with list
/// @return queue state [boolen value] 
int queue_full(void);

/// @brief Insert element into the queue
/// @param val 
void queue_put(item val);

/// @brief get the first element in the queue
/// @return the extracted item 
item queue_get(void);

/// @brief print all the elements in the queue
/// @param prefix String print before item.
/// @param suffix String print after item.
/// @param end String print at the end of the stack.
void queue_print(char *prefix, char *suffix, char *end);

#endif
