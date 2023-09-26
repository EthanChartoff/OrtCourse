#include <stdio.h>
#include <stdlib.h>

/// @brief 
/// @param a = 3 
/// @param x = 2
void P1Q1a(int *a, int *x)
{
    *a = 1;
    *x = (*a)++ * (*a)++;
}

/// @brief 
/// @param a = 1 
/// @param x = 1
void P1Q1b(int *a, int *x)
{
    *a = 1;
    *x = (*a)++ * --(*a);
}

/// @brief 
/// @param a = 3 
/// @param x = 6
void P1Q1c(int *a, int *x)
{
    int b;
    *a = b = 2;
    *x = (*a)++ * ++b;
}

/// @brief 
/// @param a = 2 
/// @param x = 0
void P1Q1d(int *a, int *x)
{
    *a = 1;
    *x = ((*a) ^ (*a)) * (*a)++;
}

/// @brief 
/// @param a = 2
/// @param x = 2
void P1Q1e(int *a, int *x)
{
    *a = 1;
    *x = ((*a) | (*a)++) * (*a);
}

/// @brief 
/// @param a = 1
/// @param x = 1
void P1Q1f(int *a, int *x)
{
    *a = 1;
    *x = ((*a) || (*a)++) * (*a);
}

/// @brief 
/// @param x = 4 
void P1Q2a(int *x)
{
    *x = 5;

    while (!((*x) | (*x)))
    (*x)++;
    (*x)--;
}

/// @brief 
/// @param x = -1 because x has a max value, overflows and becomes 0. 
void P1Q2b(int *x)
{
    *x = 5;

    while ((*x) | (*x))
    (*x)++;
    (*x)--;
}

/// @brief 
/// @param x = 4
void P1Q2c(int *x)
{
    *x = 5;

    while (((*x) ^ (*x)))
    (*x)++;
    (*x)--;
}

/// @brief 
/// @param x = 5
void P1Q2d(int *x)
{
    int z = 4;

    for(*x = 5; (*x) ^ (*x); x++)
    z++;
}

/// @brief 
/// @param a = 3 
/// @param b = 1
/// @param c = 2
void P1Q3a(int *a, int *b, int *c)
{
    *a = *b = 2;

    *c = (*a)++ * --(*b); 
}

/// @brief 
/// @param a = 1
/// @param b 
/// @param c = 1
void P1Q3b(int *a, int *b, int *c)
{
    *a = 1;

    *c = ((*a) || ((*a)++)) * (*a); 
}

/// @brief 
/// @param a = 1
/// @param b 
/// @param c = 1
void P1Q3c(int *a, int *b, int *c)
{
    *a = 1;

    *c = ((*a) || ++(*a)) * (*a); 
}


/// @brief 
/// @param a = 1
/// @param b 
/// @param c = 1
void P1Q3d(int *a, int *b, int *c)
{
    *a = 0;

    *c = ((*a) || ++(*a)) * (*a); 
}

void P1Q4a(int *x)
{
    int y;
    y = 4;
    *x = 5; 

    printf("%d\n", 5>4>2);

    while((*x)>y>2)
    (*x)++;
    (*x)--;
}

int main()
{
    int x;

    P1Q4a(&x);
    printf("%d\n", x);
    
    return 0;
}