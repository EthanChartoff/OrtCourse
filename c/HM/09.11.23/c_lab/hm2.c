#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/// @brief a*b but without the * operator.
/// @param a 
/// @param b 
/// @return 
/// @note check if there is a way to optimize this, maybe with bitwise operators
int P1(int a, int b)
{
    int result = 0;

    // if a or b is 0.
    if(!(a && b))
    {
        return 0;
    }
    // if a is positive and not 0.
    else if(a > 0)
    {
        for(int i = 0; i < a; i++)
        {
            result += b;
        }
    }
    // if a is negative
    else
    {
        for(int i = 0; i > a; i--)
        {
            result -= b;
        }
    }
    return result;
}

/// @brief implementation of / and %.
/// @param a numerator.
/// @param b denominator.
/// @return 
int* P2(int a, int b)
{
    int divResult = 0;
    int modResult = 0;
    int* result = malloc(sizeof(int) * 2 + 1);

    // if denominator of any numerator is zero,
    // the program should print that its impossible to 
    // divide by 0.
    if(!b)
    {
        printf("it's impossible to divide by zero, so the results are useless\n");
    }
    // if the numerator of any number except zero is zero, 
    // the two results should be zero.
    else if(!a) {}
    // all operation after this will devide a by b accordingly.

    // if both a and b are bigger or smaller then 0, 
    else if (b * a > 0)
    {
        int abs = a > 0 ? 1 : -1;
        while (a * abs >= b * abs)
        {
            a -= b;
            divResult++;
        }
        modResult = a;
    }
    // if a is smaller and b is bigger or vise versa
    else 
    {
        if(a > 0)
        {
            while (a >= -b)
            {
                a += b;
                divResult--;
            }
            modResult = a;
        }
        else
        {
            while (-a >= b)
            {
                a += b;
                divResult--;
            }
            modResult = a;
        }
    }
    
    result[0] = divResult;
    result[1] = modResult;
    return result;
}

/// @brief Print the number of digits, sum of digits and most left and right digits.
/// @param a 
void P3()
{
    unsigned int n = 0;

    printf("please enter a natural number: ");
    scanf("%u", &n);
    getchar(); // gets the \n char so the while wont loop again.

    // while number is zero or correct input is 0
    while(!n) 
    {
        printf("must be a natural number\n");
        scanf("%u", &n);
        getchar(); // gets the \n char
    }
    int sum = 0, counter = 0, leastSignificantDigit = n % 10, mostSignificantDigit = 0;

    while(n > 0)
    {
        if(n < 10)
        {
            mostSignificantDigit = n;
        }
        sum += n % 10;
        counter++;
        n /= 10;
    }

    printf("sum of all digits: %d\nnumber of digits: %d\nright most digit: %d\nleft most digit: %d\n", sum, counter, leastSignificantDigit, mostSignificantDigit);
}

/// @brief finds the greatest common divider of 2 integers
/// @param a 
/// @param b 
/// @return 
int P4(int a, int b)
{
    int i, greatestCommonDivider;
    for(i = 1; i <= a && i <= b; i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            greatestCommonDivider = i;
        }
    }
    return greatestCommonDivider;
}

/// @brief calculates a to the power n 
/// @param a 
/// @param n 
/// @return 
long double P5(long double a, unsigned int n)
{
    // a^0 will always be 1, unless a is 0 (which is undefined).
    if(!n)
    {
        return 1;
    }

    long double result = a;

    while (n - 1)
    {
        result *= a;
        n--;
    }
    return result;
}

/// @brief calaculates n!
/// @param n 
/// @return 
unsigned int P6a(unsigned int n)
{
    // 0! is 1.
    if(!n)
    {
        return 1;
    }

    unsigned int i, result = 1;
    for(i = 2; i <= n; i++)
    {   
        result *= i;
    }
    return result;
}

/// @brief calculates the series a^2 + 2a^4 +...+ na^2n
/// @param a 
/// @param n 
/// @return 
long double P6b(double a, unsigned int n)
{
    if(!n || !a)
    {
        return 0;
    }

    unsigned int i;
    long double result = 0;

    for(i = 1; i <= n; i++)
    {
        result += i * P5(a, 2 * i);
    }

    return result;
}

// P7 and P5 are the same

/// @brief given series defined by a_(n + 1) = n*a_n + n^2 and a_1 = 6 calculate value a_n 
/// @param n 
/// @return 
unsigned int P8(unsigned int n)
{
    unsigned int a = 6, i;

    for(i = 2; i <= n; i++)
    {
        a = i * a + P5(i, 2);
    }
    return a;
}

/// @brief finds the max 2 numbers out of a list of a 1000 numbers.
/// @param a 
/// @return 
int* P9(int* a)
{
    int* maxTwoNums = malloc(sizeof(int) * 2 + 1);
    int i = 2;
    maxTwoNums[0] = a[0], maxTwoNums[1] = a[1];
    a = a + 2;

    for(i; i < 1000; i++)
    {
        if(a[i] > maxTwoNums[0])
        {
            maxTwoNums[1] = maxTwoNums[0];
            maxTwoNums[0] = a[i];
        }
        else if(a[i] > maxTwoNums[1])
        {
            maxTwoNums[1] = a[i];
        }
    }

    return maxTwoNums;
}

/// @brief prints all 3 digit numbers that the sum of all cubed digits equals the original number.
void P10()
{
    int i = 100;
    for(i; i < 1000; i++)
    {
        if(i == P5(i / 100, 3) + P5((i / 10) % 10, 3) + P5(i % 10, 3))
        {
            printf("%d\n", i);
        }
    }
}

/// @brief prints upside-down pyramid.
void P11a()
{
    int rows = 5, i, j, space;
    
    for (i = rows; i >= 1; i--)
    {
        for (space = 0; space < rows - i; space++)
        
            printf("  ");
            
        for (j = i; j <= 2 * i - 1; j++)
        
            printf("* ");
        for (j = 0; j < i - 1; j++)
        
            printf("* ");
            
        printf("\n");
    }
}

/// @brief print pyramid.
void P11b()
{
    int i, space, rows = 5, a = 0;
    
    for (i = 1; i <= rows; i++, a = 0)
    {
        for (space = 1; space <= rows - i; space++)
        {
            printf("  ");
        }
        while (a != 2 * i - 1)
        {
            printf("* ");
            a++;
        }
        printf("\n");
    }
}

/// @brief prints an hourglass pattern of stars
void P11c()
{
    int rows = 5, i, j, space, a;
    
    for (i = rows; i > 1; i--)
    {
        for (space = 0; space < rows - i; space++)
        
            printf("  ");
            
        for (j = i; j <= 2 * i - 1; j++)
        
            printf("* ");
        for (j = 0; j < i - 1; j++)
        
            printf("* ");
            
        printf("\n");
    }

    for (i = 1; i <= rows; i++, a = 0)
    {
        for (space = 1; space <= rows - i; space++)
        {
            printf("  ");
        }
        while (a != 2 * i - 1)
        {
            printf("* ");
            a++;
        }
        printf("\n");
    }
}

/// @brief prints all of the prime factors of n (using trial division).
/// @param n 
void P12(unsigned int n)
{
    int factor = 3;

    // while n is even, 2 is a prime factor within it.
    while (n % 2 == 0)
    {
        printf("%d\n", 2);
        n /= 2;
    }

    // while still having the possability of finding a prime factor.
    while (factor * factor <= n)
    {
        // if the remainder of n divided by a number is 0, that number is a factor. 
        if(n % factor == 0)
        {
            printf("%d\n", factor);
            n /= factor;
        }
        else
        {
            factor += 2;
        }
    }

    if(n != 1)
    {
        printf("%d\n", n);
    }
}

/// @brief finds all prime numbers between left and right.
/// @param left 
/// @param right 
void P13(unsigned int left, unsigned int right)
{
    int primeFlag, i, icopy;
    for(i = left + 1; i < right; ++i)
    {
        for(icopy = i - 1, primeFlag = 1; icopy > 1; --icopy)
        {
            if(i % icopy == 0)
            {
                primeFlag = 0;
            }
        }   

        if (primeFlag)
        {
            printf("%d, ", i);
        }
    }
    printf("\n");
}

/// @brief gets number of studets and their decesions, and determines if more students voted yes or no.
void P14()
{
    unsigned int n, i, yesCounter, noCounter, vote, flag;

    printf("please enter number of students: ");
    flag = scanf("%u", &n);
    getchar();

    while (!flag)
    {
        printf("previous charachter can't be the number of students: ");
        flag = scanf("%u", &n);
        getchar();
    }
    

    for(i = 0; i < n; ++i)
    {
        printf("student number %u, do you agree? (1 for yes/0 for no): ", i);
        flag = scanf("%u", &vote);
        getchar();

        while (!(vote == 0 || vote == 1) || !flag)
        {
            printf("you must vote 0 or 1, no other characters! ");
            flag = scanf("%u", &vote);
            getchar();
        }

        if(vote)
        {
            yesCounter++;
        }
        else
        {
            noCounter++;
        }
    }

    if(yesCounter > noCounter)
    {
        printf("more students voted yes for the decision\n");
    }
    else if(noCounter > yesCounter)
    {
        printf("more students voted no for the decision\n");
    }
    else
    {
        printf("its a tie\n");
    }
}

int main()
{
    return 0;
}