#ifndef RPN_MISC_H
#define RPN_MISC_H

#define is_digit(c) ((c) >= '0' && (c) <= '9')

#define USAGE ( \
	"rpn usage:\n" \
	"$ ./rpn [EQUATION]\n" \
	"where [EQUATION] is a reverse polish notation equation to evaluate\n" \
)

#define OPERATOR_ERROR ( \
	"syntax error in equation at argument %d:\n" \
	"expected operator or operand, found '%s'\n" \
	"run without any arguments for help\n" \
)

#define RET_ERROR 1
#define RET_HELP 2
#define RET_SUCCESS 0

#endif
