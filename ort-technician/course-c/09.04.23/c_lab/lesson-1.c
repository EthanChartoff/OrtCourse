#include <stdio.h>
#include <math.h>

/*
    Problem 1
    Solve the cubic formula of a, b, c and print the results
*/
void QubicFormula(int a, int b, int c)
{
    int delta = pow(b, 2) - 4 * a * c;

    // if delta = 0, print only the 1 solution
    if(!delta)
    {
        print("%d", -b/2);
    }
    // if delta > 0, print the 2 solutions 
    else if(delta > 0)
    {
        print("%d, %d", -b+sqrt(pow(b, 2))-4 * a * c);
    }
}

int main()
{

}