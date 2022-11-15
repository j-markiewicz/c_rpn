#ifndef RPN_OPS_H
#define RPN_OPS_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define RPN_OP_ERR (0.0 / 0.0)
#define RPN_PI (3.1415926535897932384626433832795)
#define RPN_E (2.7182818284590452353602874713527)

typedef double operand;

/* A supported RPN operator (always has two arguments) */
enum Operator {
	/* =   a =   <=> print(a) */
	Eq = 1,
	/* +   a b + <=> a + b */
	Add,
	/* -   a b - <=> a - b */
	Sub,
	/* --  a -   <=> -a */
	Neg,
	/* *   a b * <=> a * b */
	Mul,
	/* /   a b / <=> a / b */
	Div,
	/* ^  a b ** <=> a b ^ <=> a^b <=> a * a * ... * a */
	Pow,
	/* ln  a ln  <=> ln(a) */
	Ln,
	/* triangle  a b c triangle <=> can a triangle with sides of length a, b, and c exist? (1 or 0) */
	Triangle,
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

/* Return the number of arguments this operator needs */
uint64_t op_args(enum Operator);

#endif
