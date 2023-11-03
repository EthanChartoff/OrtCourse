#include <stdio.h>
#include <stdlib.h>

/// @brief find max value in int array
/// @param arr
/// @param len
/// @return
int Q1a(int arr[], size_t len) {
	int max = arr[0], i;

	for (i = 1; i < len; ++i) max = max >= arr[i] ? max : arr[i];

	return max;
}

/// @brief find index of max value in int array
/// @param arr
/// @param len
/// @return
int Q1b(int arr[], size_t len) {
	int max_index = 0, i;

	for (i = 1; i < len; ++i)
		arr[max_index] >= arr[i] ? arr[max_index] : arr[i];

	return max_index;
}

/// @brief find max value of two consecutive elements
/// @param arr
/// @param len
/// @return
int Q2a(int arr[], size_t len) {
	int max = arr[0] + arr[1], i;

	for (i = 1; i < len - 1; ++i)
		max = max < arr[i] + arr[i + 1] ? arr[i] + arr[i + 1] : max;

	return max;
}

/// @brief find max value of three consecutive elements
/// @param arr
/// @param len
/// @return
int Q2b(int arr[], size_t len) {
	int max = arr[0] + arr[1] + arr[2], i;

	for (i = 1; i < len - 2; ++i)
		max = max < arr[i] + arr[i + 1] + arr[i + 2]
				  ? arr[i] + arr[i + 1] + arr[i + 2]
				  : max;

	return max;
}

/// @brief rotate an arr to the left by shamt
/// @param arr
/// @param len
/// @param shamt shift amount
void Q3a(int arr[], size_t len, unsigned int shamt) {
	int *temp;
	int i, quotient;
	int real_shamt = shamt % len;

	temp = malloc(real_shamt * sizeof(int));

	for (i = 0; i < real_shamt; ++i) temp[i] = arr[i];

	for (i = 0; i < len - real_shamt; ++i) arr[i] = arr[i + real_shamt];

	for (i = 0; i < real_shamt; ++i) arr[i + len - real_shamt] = temp[i];

	free(temp);
}

/// @brief rotate arr to the right by shamt
/// @param arr
/// @param len
/// @param shamt shift amount
void Q3b(int arr[], size_t len, unsigned int shamt) {
	int *temp;
	int i;
	int real_shamt = shamt % len;

	temp = malloc(len * sizeof(int));

	for (i = 0; i < len; ++i) temp[(i + real_shamt) % len] = arr[i];

	for (i = 0; i < len; ++i) arr[i] = temp[i];

	free(temp);
}

/// @brief print arr using ++
/// @param arr
/// @param len
void Q4a(int arr[], size_t len) {
	int i;

	for (i = 0; i < len; ++i) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

/// @brief print arr using --
/// @param arr
/// @param len
void Q4b(int arr[], size_t len) {
	int i;

	for (i = len - 1; i >= 0; --i) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

/// @brief check if arr palindrome
/// @param arr
/// @param len
/// @return
int Q5(int arr[], size_t len) {
	int i;

	for (i = 0; i < len / 2; ++i)
		if (arr[i] != arr[len - 1 - i]) return 0;

	return 1;
}

/// @brief merge two sorted arrays into one big sorted array
/// @param a sorted arr
/// @param lena
/// @param b sorted arr
/// @param lenb
/// @param c big array
/// @return
void Q7(int a[], size_t lena, int b[], size_t lenb, int c[]) {
	int i;
	int a_index = 0, b_index = 0;

	for (i = 0; i < lena + lenb; ++i) {
		if (a_index >= lena) {
			c[i] = b[b_index++];
		} else if (b_index >= lenb) {
			c[i] = a[a_index++];
		} else {
			c[i] = a[a_index] < b[b_index] ? a[a_index++] : b[b_index++];
		}
	}
}

void Q8(int a[], size_t len) {
	int i;
	int *odd_arr, *even_arr;
	int odd_index, even_index;

	odd_arr = (int *)malloc(len * sizeof(int));
	even_arr = (int *)malloc(len * sizeof(int));

	for (i = 0; i < len; ++i)
		if (a[i] % 2)
			odd_arr[odd_index++] = a[i];
		else
			even_arr[even_index++] = a[i];

	for (i = 0; i < odd_index; ++i) printf("%d, ", odd_arr[i]);
	printf("\n");
	for (i = 0; i < even_index; ++i) printf("%d, ", even_arr[i]);
}

int main(void) {}