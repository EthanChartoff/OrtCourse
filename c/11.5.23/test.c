#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void main()
{
	int *ptr, *arr[MAX];
	int i, j;
	for (i=MAX-1;i>=0; i--)
	{
	    if (arr[i] = (int *) malloc(i * sizeof(int)))
	    for (j=0; j<i; j++)
	        *(*(arr+i)+j) = j*i;

	}
	ptr = &arr[9][8];
	while (*ptr)
	    printf("%d, ", *ptr--);
}
