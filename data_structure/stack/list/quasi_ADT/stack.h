#ifndef _STACK
#define _STACK

typedef int item;

/**
 * @brief Initialize stack.
 *
 * You can only initilize one stack at the time.
 *
 * @param n_max
 * Maximum number of elements in the stack. [not necessary with the list]
 */
void stack_init(int n_max);

/// @brief Free the stack.
void stack_free(void);

/**
 * @brief
 * Check if stack is empty.
 * @return
 * - `1` --> empty
 *
 * - `0` --> not empty
 */
int stack_empty(void);

/**
 * @brief
 * Check if stack is full.
 * @return
 * - `1`--> full
 *
 * - `0` --> not full
 */
int stack_full(void);

/**
 * @brief Insert item in the stack.
 *
 * @param val
 * Item you want insert
 */
void stack_push(item val);

/**
 * @brief Extract item in the stack.
 *
 * @return item
 * if it's `-1` the pop wasn't done becuase there is a `Stack error` or a `Pop error`.
 */
item stack_pop(void);

/**
 * @brief Print all elements in the stack.
 *
 * @param prefix String print before item.
 * @param suffix String print after item.
 * @param end String print at the end of the stack.
 */
void print_stack(char *prefix, char *suffix, char *end);

#endif