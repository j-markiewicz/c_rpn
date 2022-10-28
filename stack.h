#ifndef RPN_STACK_H
#define RPN_STACK_H

#include <stdint.h>

#include "ops.h"

#define STACK_DEFAULT_CAP 8

/* A dynamically sized stack storing RPN values on the heap, while allowing push
 * and pop operations.
 */
struct Stack {
	size_t cap;
	operand* base;
	operand* head;
};

/* Create a new Stack with a default capacity */
struct Stack stack_new();

/* Create a new Stack with the given capacity */
struct Stack stack_new_with_cap(size_t);

/* Free the given Stack */
void stack_free(struct Stack);

/* Resize the given Stack to have the given capacity. If the new capacity is not
 * enough to fit all current items, some items will be lost.
 */
void stack_resize(struct Stack*, size_t);

/* Push an item onto the stack */
void stack_push(struct Stack*, operand);

/* Pop an item from the stack. If the stack is empty, returns RPN_OP_ERR */
operand stack_pop(struct Stack*);

#endif
