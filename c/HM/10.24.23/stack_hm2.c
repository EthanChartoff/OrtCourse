#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "calculator_stack/calculator_stack.h"

/// @brief gets binary math equation and returns the result using the calculator
/// stack
/// @param equation
/// @return result of equation
int P1(char *equation) {
	Stack s;
	stack_init(&s);

	int i = 0, num1, num2, result;
	char operator;

	for (; equation[i] != '\0'; ++i) {
		if (equation[i] != ')') {
			// push all symobols into stack until program gets to a closing
			// paren
			push(&s, equation[i]);
		} else {
			/// when program gets to a closing paren, get numbers and operator
			/// beforehand, calc and push result
			num2 = pop(&s) - '0';
			operator= pop(&s);
			num1 = pop(&s) - '0';
			pop(&s);

			switch (operator) {
				case '+':
					result = num1 + num2;
					break;
				case '-':
					result = num1 - num2;
					break;
				case '*':
					result = num1 * num2;
					break;
				case '/':
					result = num1 / num2;
					break;
				case '^':
					result = pow(num1, num2);
					break;
				default:
					break;
			}

			push(&s, result + '0');
		}
	}

	return pop(&s) - '0';
}

/// @brief gets a postfix equation and returns the result using the calculator
/// stack
/// @param equation
/// @return
int P2(char *equation) {
	Stack s;
	stack_init(&s);

	int i = 0, num1, num2, result;

	for (; equation[i] != '\0'; ++i) {
		if (is_literal(equation[i])) {
			push(&s, equation[i]);
		} else if (is_operator(equation[i])) {
			num2 = pop(&s) - '0';
			num1 = pop(&s) - '0';

			switch (equation[i]) {
				case '+':
					result = num1 + num2;
					break;
				case '-':
					result = num1 - num2;
					break;
				case '*':
					result = num1 * num2;
					break;
				case '/':
					result = num1 / num2;
					break;
				case '^':
					result = pow(num1, num2);
					break;
				default:
					break;
			}
			push(&s, result + '0');
		}
	}

	return pop(&s) - '0';
}

/// @brief converts infix to postfix
/// @param s
/// @return
char *P3(char *s) {
	Stack stack;
	stack_init(&stack);

	char *postfix = (char *)malloc(sizeof(char) * 100);
	int i = 0, j = 0;

	for (; s[i] != '\0'; ++i) {
		if (is_literal(s[i]) && s[i] != ' ') {
			postfix[j++] = s[i];
		} else if (is_operator(s[i])) {
			if (stack_empty(stack)) {
				push(&stack, s[i]);
			} else {
				while (!stack_empty(stack) && stack.data[stack.top] != '(' &&
					   precedence(s[i]) <= precedence(stack.data[stack.top])) {
					postfix[j++] = pop(&stack);
				}
				push(&stack, s[i]);
			}
		} else if (s[i] == '(') {
			push(&stack, s[i]);
		} else if (s[i] == ')') {
			while (!stack_empty(stack) && stack.data[stack.top] != '(') {
				postfix[j++] = pop(&stack);
			}
			pop(&stack);
		}
	}

	while (!stack_empty(stack)) {
		postfix[j++] = pop(&stack);
	}

	postfix[j] = '\0';

	return postfix;
}

/// @brief gets binary math equation and returns the result using the calculator
/// stack (numbers can be more than one digit)
/// @param equation
/// @return result of equation
int P4(char *equation) {
	Stack s, temp;
	stack_init(&s);
	stack_init(&temp);

	int i = 0, num1, num2, result;
	char operator;

	for (; equation[i] != '\0'; ++i) {
		if (equation[i] != ')') {
			// push all symobols into stack until program gets to a closing
			// paren
			push(&s, equation[i]);
		} else {
			num1 = 0;
			num2 = 0;

			/// when program gets to a closing paren, get numbers and operator
			/// beforehand, calc and push result
			while (is_literal(s.data[s.top])) {
				push(&temp, pop(&s));
			}
			while (!stack_empty(temp)) {
				num2 *= 10;
				num2 += pop(&temp) - '0';
			}

			operator= pop(&s);

			while (is_literal(s.data[s.top])) {
				push(&temp, pop(&s));
			}
			while (!stack_empty(temp)) {
				num1 *= 10;
				num1 += pop(&temp) - '0';
			}

			pop(&s);

			switch (operator) {
				case '+':
					result = num1 + num2;
					break;
				case '-':
					result = num1 - num2;
					break;
				case '*':
					result = num1 * num2;
					break;
				case '/':
					result = num1 / num2;
					break;
				case '^':
					result = pow(num1, num2);
					break;
				default:
					break;
			}

			do {
				push(&temp, (result % 10) + '0');
				result /= 10;
			} while (result != 0);

			while (!stack_empty(temp)) {
				push(&s, pop(&temp));
			}
		}
	}

	result = 0;

	flip(&s);
	while (!stack_empty(s)) {
		result *= 10;
		result += pop(&s) - '0';
	}

	return result;
}

int main(void) { return 0; }