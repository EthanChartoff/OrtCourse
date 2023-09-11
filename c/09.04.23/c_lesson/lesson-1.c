// The operating system starts the program by calling the main() function.

#include <stdio.h>


int main()
{
    int val1, val2;

    printf("please enter two integers: \n");
    scanf("%d, %d\n", &val1, &val2);
    printf("%d, %d\n", val1, val2);

    return 0;
}