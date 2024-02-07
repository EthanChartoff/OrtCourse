#include <stdio.h>

int *a[5]; // arr of integer pointers
int (*a)[5]; // pointer to arr of integers (not integer pointers)

int main(void) {
	int mat[2][3] = {345, 12, 23, 92, 45, 76};
	int *p1[] = {*mat + 2, *(mat + 1) + 1, *(mat + 1) - 2};
	int **p2[] = {p1 + 1, p1 + 2, p1};
	int ***p3 = p2;

	printf("%d\n", ++*--*++*p3); // 346
	printf("%d\n", *(*p3[2] - 1)); // 12
	printf("%d\n", *(p3[0][-1] + 1)); // 76
	printf("%d\n", *(*(*(p3+2) + 2))); // 346
}
