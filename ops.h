#ifndef RPN_OPS_H
#define RPN_OPS_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define RPN_OP_ERR NAN

typedef double operand;

/* A supported RPN operator (always has two arguments) */
enum Operator {
	/* +   a b + <=> a + b */
	Add = 1,
	/* -   a b - <=> a - b */
	Sub,
	/* *   a b * <=> a * b */
	Mul,
	/* /   a b / <=> a / b */
	Div,
	/* ERROR */
	Err = 0
};

/* An RPN operator/operand */
struct Op {
	bool is_operator;
	union {
		operand operand;
		enum Operator operator;
	} op;
};

/* Parse an operator/operand from the provided string */
struct Op parse_arg(const char*);

#endif
