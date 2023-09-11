#include <stdio.h>

/// @brief a*b but without the * operator.
/// @param a 
/// @param b 
/// @return 
/// @note check if there is a way to optimize this, maybe with bitwise operators
int MulWithFor(int a, int b)
{
    // if a or b is 0.
    if(!(a && b))
    {
        return 0;
    }
    // if a is positive and not 0.
    else if(a > 0)
    {
        for(int i = 1; i < a; i++)
        {
            b += b;
        }
    }
    // if a is negative
    else
    {
        for(int i = -1; i > a; i--)
        {
            b -= b;
        }
    }
    return b;
}

int main()
{
    printf("%d\n", MulWithFor(3, 2));
}