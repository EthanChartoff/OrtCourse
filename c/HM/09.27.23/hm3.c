#include <math.h>
#include <stdio.h>

/// @brief reads up to 1000 numbers and prints the two largest numbers
void P1() {
	int arr[1001];
	int flag = 1, i = 0, curr, max, second_max;

	// reads
	for (; flag && i < 1000; ++i) {
		scanf("%d", &curr);

		if (curr == -999) {
			printf(
				"do you want to end the inputs or continue? (1 for yes or 0 "
				"for no): ");
			scanf("%d", &flag);

			if (flag) {
				arr[i] = curr;
			} else {
				--i;
			}
		} else {
			arr[i] = curr;
		}
	}
	--i;

	// find two largest nums
	if (arr[i] > arr[i - 1]) {
		max = arr[i];
		second_max = arr[i - 1];
	} else {
		max = arr[i - 1];
		second_max = arr[i];
	}

	for (i -= 2; i > 0; --i) {
		if (arr[i] > max) {
			second_max = max;
			max = arr[i];
		} else if (arr[i] > second_max) {
			second_max = arr[i];
		}
	}

	printf("largest num: %d\nsecond largest num: %d\n", max, second_max);
}

/// @brief calc n!
/// @param n
/// @return
unsigned int P2(unsigned int n) {
	int total = 1;

	for (; n > 1; n--) {
		total *= n;
	}
	return total;
}

/// @brief prints all 3 digit numbers that the sum of all cubed digits equals
/// the original number.
void P3() {
	int i = 100;
	for (; i < 1000; i++) {
		if (i == pow(i / 100, 3) + pow((i / 10) % 10, 3) + pow(i % 10, 3)) {
			printf("%d\n", i);
		}
	}
}

/// @brief finds all prime numbers between left and right.
/// @param left
/// @param right
void P4(unsigned int left, unsigned int right) {
	int primeFlag, i, icopy;
	for (i = left + 1; i < right; ++i) {
		for (icopy = i - 1, primeFlag = 1; icopy > 1; --icopy) {
			if (i % icopy == 0) {
				primeFlag = 0;
			}
		}

		if (primeFlag) {
			printf("%d, ", i);
		}
	}
	printf("\n");
}

/// @brief print pyramid of stars.
void P5() {
	int n = 4;	// Number of rows in the pyramid

	for (int i = 1; i <= n; i++) {
		// Calculate the number of spaces and stars for each row
		int num_spaces = n - i;
		int num_stars = 2 * i - 1;

		printf("%*s", num_spaces, "");

		// Print stars
		for (int j = 1; j <= num_stars; j++) {
			printf("*");
		}

		printf("\n");
	}
}

/// @brief returns the number of low case letters
/// @param str
/// @return
unsigned int P6(char str[]) {
	int counter = 0, i;

	for (i = 0; str[i] != '\0'; ++i) {
		if (str[i] >= 'a' && str[i] <= 'z') ++counter;
	}

	return counter;
}

/// @brief returns x with its numbers reversed.
/// @param x
/// @return
/// @note the func returns a double and not an unsigned int because doubles have
/// a larger number range, if the func would have returned an unsigned int,
/// 1999999999 would have been 9999999991 reversed, which is not in the unsigned
/// int range.
double P7(unsigned int x) {
	double reverse = 0;

	while (x) {
		reverse *= 10;
		reverse += x % 10;
		x /= 10;
	}

	return reverse;
}

/// @brief finds the missing element in the array.
/// @param a has {1, 2,..., n} elements with one missing.
/// @param n length of a + 1
/// @return
/// @todo check if you can optimize this.
unsigned int P8(unsigned int a[], unsigned int n) {
	int counter, i;

	for (i = 1; i <= n; counter += i, ++i)
		;
	for (i = 0; i < n - 1; ++i) {
		counter -= a[i];
	}

	return counter;
}

/// @brief check if a pattern similiar to the one in the first n elements can be
/// found in the string.
/// @param str
/// @param n
/// @return
int P9(char str[], unsigned int n) {
	int i, j, sameFlag;

	for (i = n; str[i] != '\0'; ++i) {
		sameFlag = 1;

		for (j = 0; j < n; ++j) {
			if (str[j] != str[j + i]) {
				sameFlag = 0;
			}
		}

		if (sameFlag) return 1;
	}

	return 0;
}

int main() { return 0; }