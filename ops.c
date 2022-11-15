#include <stdlib.h>
#include <string.h>

#include "ops.h"
#include "misc.h"

struct Op parse_arg(const char* str) {
	struct Op op;

	if (is_digit(str[0]) || (str[0] == '-' && is_digit(str[1]))) {
		op.op.operand = strtod(str, NULL);
		op.is_operator = false;
	} else if (strcmp(str, "e") == 0) {
		op.op.operand = RPN_E;
		op.is_operator = false;
	} else if (strcmp(str, "pi") == 0) {
		op.op.operand = RPN_PI;
		op.is_operator = false;
	} else {
		op.is_operator = true;

		if (strcmp(str, "=") == 0) {
			op.op.operator = Eq;
		} else if (strcmp(str, "+") == 0) {
			op.op.operator = Add;
		} else if (strcmp(str, "-") == 0) {
			op.op.operator = Sub;
		} else if (strcmp(str, "--") == 0) {
			op.op.operator = Neg;
		} else if (strcmp(str, "*") == 0 || strcmp(str, "x") == 0) {
			op.op.operator = Mul;
		} else if (strcmp(str, "/") == 0) {
			op.op.operator = Div;
		} else if (strcmp(str, "**") == 0 || strcmp(str, "^") == 0) {
			op.op.operator = Pow;
		} else if (strcmp(str, "ln") == 0) {
			op.op.operator = Ln;
		} else if (strcmp(str, "triangle") == 0) {
			op.op.operator = Triangle;
		} else {
			op.op.operator = Err;
		}
	}

	return op;
}

uint64_t op_args(enum Operator op) {
	switch (op) {
		case Neg:
		case Ln:
			return 1;
		case Triangle:
			return 3;
		default:
			return 2;
	}
}
