#include <stdlib.h>

#include "stack.h"

struct Stack stack_new() {
	return stack_new_with_cap(STACK_DEFAULT_CAP);
}

struct Stack stack_new_with_cap(size_t initial_cap) {
	struct Stack stack;

	stack.cap = initial_cap;
	stack.base = malloc(initial_cap * sizeof(operand));
	stack.head = stack.base;

	return stack;
}

void stack_free(struct Stack self) {
	free(self.base);
}

void stack_resize(struct Stack* self, size_t new_cap) {
	size_t len = self->head - self->base;

	self->base = realloc(self->base, new_cap);
	self->head = self->base + len;
}

void stack_push(struct Stack* self, operand value) {
	if (self->head - self->base == self->cap) {
		stack_resize(self, self->cap * 2);
	}

	*self->head = value;
	self->head++;
}

operand stack_pop(struct Stack* self) {
	if (self->head == self->base) {
		return RPN_OP_ERR;
	}

	self->head--;
	return *self->head;
}
