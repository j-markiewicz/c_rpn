#include <stdlib.h>

#include "ops.h"
#include "misc.h"

struct Op parse_arg(const char* str) {
	struct Op op;

	if (is_digit(str[0]) || (str[0] == '-' && is_digit(str[1]))) {
		op.op.operand = strtod(str, NULL);
		op.is_operator = false;
	} else {
		op.is_operator = true;

		switch (str[0]) {
			case '+':
				op.op.operator = Add;
				break;
			case '-':
				op.op.operator = Sub;
				break;
			case '*':
				op.op.operator = Mul;
				break;
			case '/':
				op.op.operator = Div;
				break;
			default:
				op.op.operator = Err;
				break;
		}
	}

	return op;
}
