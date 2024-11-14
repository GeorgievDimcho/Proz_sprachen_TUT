#include <stdio.h>

// Function Prototype
int fib(int);
// Main function
int main()
{
    int x;
    printf("which element of the Fibonnaci-Sequence do you need: ");
    scanf("%i", &x);
    int result = fib(x);
    printf("the fib_zahl = %d\n", result);
    return 0;


int fib(int x) // Formal Parameters
{
    int result;
    if (x == 0)
    {
        printf("0\n");
        return 0;
    }
    else if (x == 1)
    {
        printf("1\n");
        return 1;
    }
    else
    {
        // fib(n) = fib(n-1) + fib(n-2)
        result = fib(x - 1) + fib(x - 2);
        printf("%d. Fibonnaci-Zahl = %d\n", x, result);
    }
    return result;
}