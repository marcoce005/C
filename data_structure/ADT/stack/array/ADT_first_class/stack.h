#ifndef _STACK
#define _STACK

typedef int item;

typedef struct stack *Stack;

/**
 * @brief Initialize stack.
 * @param n_max
 * Maximum number of elements in the stack.
 * @return
 * Stack pointer.
 */
Stack stack_init(int n_max);

/**
 * @brief Free the stack.
 * @param sp
 * Stack pointer.
 */
void stack_free(Stack sp);

/**
 * @brief
 * Check if stack is empty.
 * @param sp
 * Stack pointer.
 * @return
 * - `1` --> empty
 *
 * - `0` --> not empty
 */
int stack_empty(Stack sp);

/**
 * @brief
 * Check if stack is full.
 * @param sp
 * Stack pointer.
 * @return
 * - `1`--> full
 *
 * - `0` --> not full
 */
int stack_full(Stack sp);

/**
 * @brief Insert item in the stack.
 * @param sp
 * Stack pointer.
 * @param val
 * Item you want insert
 */
void stack_push(Stack sp, item val);

/**
 * @brief Extract item in the stack.
 * @param sp
 * Stack pointer.
 * @return item
 * if it's `-1` the pop wasn't done becuase there is a `Stack error` or a `Pop error`.
 */
item stack_pop(Stack sp);

/**
 * @brief Print all elements in the stack.
 * @param sp
 * Stack pointer.
 * @param prefix String print before item.
 * @param suffix String print after item.
 * @param end String print at the end of the stack.
 */
void print_stack(Stack sp, char *prefix, char *suffix, char *end);

#endif
