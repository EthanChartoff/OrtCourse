#include <stdio.h>

#include "../../stack.h"

/// @brief Checks if string is a palindrome.
/// @param s
/// @return
int P1(char *s) {
	char *s_copy = s;
	int length = 0, i;
	Stack stk;

	stack_init(&stk);

	for (i = 0; s[i] != '\0'; i++, length++)
		;

	for (i = 0; i < length / 2; ++i) {
		push(&stk, s[i]);
	}

	if (length % 2 == 1) {
		++i;
	}

	for (i; i < length; ++i) {
		if (s[i] != pop(&stk)) {
			return 0;
		}
	}

	return 1;
}

/// @brief Checks if s is a string with a dot that has two equal nummbers before
/// and after the dot.
/// @param s
/// @return
int P2(char *s) {
	int i;
	Stack stk;

	stack_init(&stk);

	for (i = 0; s[i] != '.' && s[i] != '\0' && (s[i] >= '0' && s[i] <= '9');
		 push(&stk, s[i]), i++)
		;

	// if stack is empty, there is no dot.
	if (s[i] == '\0') {
		return 0;
	}

	flip(&stk);
	++i;

	for (i; s[i] != '\0'; ++i) {
		// compare digits
		if (s[i] != pop(&stk)) {
			return 0;
		}
	}

	if (!stack_empty(stk)) {
		return 0;
	}

	return 1;
}

/// @brief Reads n digits and arranges them (largest number is in top).
/// @param n number of digits to put in stack
/// @return
Stack P3(int n) {
	int i, input, format_input;
	Stack stk, tmp;

	stack_init(&stk);

	printf("please enter some numbers to be arranged in a stack:\n");

	for (i = 0; i < n; ++i) {
		format_input = scanf("%d", &input);
		getchar();

		while (!format_input) {
			printf("must be a number\n");
			format_input = scanf("%d", &input);
			getchar();	// gets the \n char
		}

		if (stack_empty(stk)) {
			push(&stk, input);
		} else {
			stack_init(&tmp);

			while (top(stk) > input) {
				push(&tmp, pop(&stk));
			}

			push(&stk, input);

			while (!stack_empty(tmp)) {
				push(&stk, pop(&tmp));
			}
		}
	}

	return stk;
}

/// @brief Gets two sorted stacks and merges them into one sorted stack.
/// @param s1
/// @param s2
/// @return
Stack P4(Stack s1, Stack s2) {
	stack_item top1, top2;
	Stack s;
	int flag;

	stack_init(&s);
	top1 = stack_empty(s1) ? pop(&s2) - 1 : pop(&s1);
	top2 = stack_empty(s2) ? pop(&s1) - 1 : pop(&s2);

	while (flag) {
		flag = !stack_empty(s1) || !stack_empty(s2);

		if (top1 > top2) {
			push(&s, top1);
			top1 = stack_empty(s1) ? top(s2) - 1 : pop(&s1);
		} else {
			push(&s, top2);
			top2 = stack_empty(s2) ? top(s1) - 1 : pop(&s2);
		}
	}

	flip(&s);
	return s;
}

/// @brief Checks if str is in lang L = {A^nB^n | n >= 0}.
/// @param str
/// @return
int P5(char str[]) {
	int i;
	Stack stk;

	stack_init(&stk);

	for (i = 0; str[i] != '\0' && str[i] != 'B'; ++i) {
		if (str[i] != 'A') return 0;
		push(&stk, 'A');
	}

	for (; str[i] != '\0'; ++i) {
		if (str[i] != 'B') return 0;
		pop(&stk);
	}

	return stack_empty(stk);
}

/// @brief Checks if str is in lang L = {xCy | x E {A,B}+ and y E {A,B}+ and y =
/// x_r}.
/// @param str
/// @return
int P6(char str[]) {
	int i;
	Stack stk;

	stack_init(&stk);

	for (i = 0; str[i] == 'A' || str[i] == 'B'; ++i) push(&stk, str[i]);

	if (str[i] != 'C') return 0;

	for (++i; str[i] == 'A' || str[i] == 'B'; ++i) {
		if (str[i] != pop(&stk)) return 0;
	}

	return stack_empty(stk) && i > 1;
}

/// @brief Checks if str is in lang L = {xCyCx | x E {A,B}+ and y E {A,B}+ and y
/// = x_r}.
/// @param str
/// @return
int P7(char str[]) {
	int i;
	Stack s1, s2;

	stack_init(&s1), stack_init(&s2);

	for (i = 0; str[i] == 'A' || str[i] == 'B'; ++i) push(&s1, str[i]);

	if (str[i] != 'C') return 0;

	for (++i; str[i] == 'A' || str[i] == 'B'; ++i) {
		if (str[i] != top(s1)) return 0;
		push(&s2, pop(&s1));
	}

	if (str[i] != 'C') return 0;

	for (++i; str[i] == 'A' || str[i] == 'B'; ++i) {
		if (str[i] != pop(&s2)) return 0;
	}

	return stack_empty(s1) && stack_empty(s2) && i > 2;
}

int main() {}