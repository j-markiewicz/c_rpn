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
			double operands[op_args(op.op.operator)];
			double res = 0.0;

			switch (op.op.operator) {
				case Eq:
					operands[0] = stack_pop(&stack);
					printf("%g\n", operands[0]);
					res = operands[0];
					break;
				case Add:
					operands[0] = stack_pop(&stack);
					operands[1] = stack_pop(&stack);
					res = operands[1] + operands[0];
					break;
				case Sub:
					operands[0] = stack_pop(&stack);
					operands[1] = stack_pop(&stack);
					res = operands[1] - operands[0];
					break;
				case Neg:
					operands[0] = stack_pop(&stack);
					res = -operands[0];
					break;
				case Mul:
					operands[0] = stack_pop(&stack);
					operands[1] = stack_pop(&stack);
					res = operands[1] * operands[0];
					break;
				case Div:
					operands[0] = stack_pop(&stack);
					operands[1] = stack_pop(&stack);
					res = operands[1] / operands[0];
					break;
				case Pow:
					operands[0] = stack_pop(&stack);
					operands[1] = stack_pop(&stack);
					res = pow(operands[1], operands[0]);
					break;
				case Ln:
					operands[0] = stack_pop(&stack);
					res = log(operands[0]);
					break;
				case Triangle:
					operands[0] = stack_pop(&stack);
					operands[1] = stack_pop(&stack);
					operands[2] = stack_pop(&stack);
					res = (operands[0] + operands[1] > operands[2]
					   && operands[1] + operands[2] > operands[0]
					   && operands[2] + operands[0] > operands[1]) ? 1.0 : 0.0;
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

	printf("= %g\n", res);

	return RET_SUCCESS;
}
