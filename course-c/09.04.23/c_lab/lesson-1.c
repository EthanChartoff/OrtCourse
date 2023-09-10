#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/// Problem 1
/// @brief Solve the cubic formula of a, b, c and print the results.
/// @param a integer a of the cubic formula.
/// @param b integer b of the cubic formula.
/// @param c integer c of the cubic formula.
void QubicFormula(int a, int b, int c)
{
    int delta = pow(b, 2) - 4 * a * c;

    // if delta = 0, print only the 1 solution.
    if(!delta)
    {
        printf("%f", (double) -b/(2 * a));
    }
    // if delta > 0, print the 2 solutions.
    else if(delta > 0)
    {
        printf("%f, %f", (-b + sqrt(delta))/(2 * a), (-b - sqrt(delta))/(2 * a));
    }
    // if delta < 0, there is no solution to the equation.
    else
    {
        printf("no real solution");
    }
    printf("\n");
}

/// @brief same as QubicFormula but the characters are inputed by the user.
/// @return 0 if everything went well, 1 if not.
int InputQubicFormula()
{
    int a, b, c;

    printf("please enter 3 integers to solve the cubic formula with, in this format: a, b, c\n");
    if(scanf("%d, %d, %d", &a, &b, &c) == 3)
    {
        QubicFormula(a, b, c);
        return 0;
    }

    printf("invalid format\n");
    return 1;
}

/// Problem 2
/// @brief Converts Seconds to hh:mm:ss, for example if seconds is 4000 the output will be 01:06:40.
/// @param seconds number of seconds to be converted.
char* SecondsToHMS(unsigned int seconds)
{
    int hours, minutes;
    char *time = malloc(9);

    hours = seconds/3600;
    minutes = (seconds%3600)/60;
    seconds %= 60;

    sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);

    return time;
}

/// @brief same as SecondsToHMS but the user inputs the values.
/// @return 0 if everything went well, 1 if not.
int InputSecondsToHMS() 
{
    unsigned int seconds;

    printf("please input seconds to be converted into time format hh:mm:dd\n");
    if(scanf("%u", &seconds) == 1)
    {
        printf("%s\n", SecondsToHMS(seconds));
        return 0;
    }

    printf("invalid input\n");
    return 1;
}

/// @brief Finds greatest value between the integers a, b and c.
/// @param a an integer.
/// @param b an integer.
/// @param c an integer.
int FindMax(int a, int b, int c)
{
    int max;

    max = a > b + c ? a : b;
    return max > c ? max : c;
}

/// @brief same as FindMax but the values are user inputed.
int InputFindMax()
{
    int a, b, c;

    printf("please enter 3 integers in this format: a, b, c. the program will find the greatest integer.\n");
    if(scanf("%d, %d, %d", &a, &b, &c) == 3)
    {
        printf("the greatest integer is: %d\n", FindMax(a, b, c));
        return 0;
    }
    printf("invalid input\n");
    return 1;
}

/// @brief First of all, check if the given params can form a triangle. 
/// If a triangle can be formed, check if the triangle is right-angled, obtuse or sharp. 
/// After that check if its isosceles or equilateral. Print a message according to each condition 
/// @param a 
/// @param b 
/// @param c 
void CheckTriangle(int a, int b, int c)
{
    int max, min1, min2;

    // check if the given params can form a triangle.
    if(a + b > c && a + c > b && b + c > a)
    {
        // check if the triangle is right-angled, obtuse or sharp.
        max = FindMax(a, b, c);
        min1 = a < b + c ? a : b;
        min2 = b < a + c ? b : c;

        if(pow(max, 2) == pow(min1, 2) + pow(min2, 2))
        {
            printf("right-angled triangle\n");
        }
        else if(pow(max, 2) > pow(min1, 2) + pow(min2, 2))
        {
            printf("obtuse triangle\n");
        }
        else
        {
            printf("sharp triangle\n");
        }

        // check if its isosceles or equilateral.
        if(a == b || a == c || b == c)
        {
            if(a == b && a == c)
            {
                printf("equilateral triangle\n");
            }
            else
            {
                printf("isosceles triangle\n");
            }
        }
        else
        {
            printf("scalene triangle\n");
        }
    }
    else
    {
        printf("the given params can't form a triangle\n");
    }
}

/// @brief sort the vals in between themselves, such that a will have the lowest value, b the second lowest and so on.
/// @param a sorted to be the lowest value.
/// @param b sorted to be the second lowest value.
/// @param c sorted to be the third lowest value.
/// @param d sorted to be the highest value.
void SortVals(int a, int b, int c, int d)
{
    int temp;

    if(a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    if(a > c)
    {
        temp = a;
        a = c;
        c = temp;
    }

    if(a > d)
    {
        temp = a;
        a = d;
        d = temp;
    }

    if(b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }

    if(b > d)
    {
        temp = b;
        b = d;
        d = temp;
    }

    if(c > d)
    {
        temp = c;
        c = d;
        d = temp;
    }

    printf("%d, %d, %d, %d\n", a, b, c, d);
}

/// @brief same as SortVals but the values are user inputed.
/// @param year 
void IsLeapYear(int year)
{
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        printf("leap year\n");
    }
    else
    {
        printf("not a leap year\n");
    }
}


int main()
{
    return InputFindMax();
}