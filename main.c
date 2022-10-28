#include <stdint.h>
#include <stdio.h>

#include "misc.h"
#include "ops.h"
#include "stack.h"

int32_t main(int32_t argc, char** argv) {
	if (argc < 2) {
		printf(USAGE);
		return RET_HELP;
	}

	struct Stack stack = stack_new();

	int32_t i;
	for (i = 1; i < argc; i++) {
		struct Op op = parse_arg(argv[i]);

		if (op.is_operator) {
			operand b = stack_pop(&stack);
			operand a = stack_pop(&stack);

			double res = 0.0;
			switch (op.op.operator) {
				case Add:
					res = a + b;
					break;
				case Sub:
					res = a - b;
					break;
				case Mul:
					res = a * b;
					break;
				case Div:
					res = a / b;
					break;
				case Err:
					printf(OPERATOR_ERROR, i, argv[i]);
					return RET_ERROR;
			}

			stack_push(&stack, res);
		} else {
			stack_push(&stack, op.op.operand);
		}
	}

	operand res = stack_pop(&stack);
	stack_free(stack);

	printf("= %g", res);

	return RET_SUCCESS;
}
