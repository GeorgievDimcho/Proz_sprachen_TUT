#include <stdio.h>

// Function Prototype
void swapx(int x, int y);

// Main function
int main()
{
    int a = 10, b = 20;
    // |a=10|a=20|b=20|b=10|

    // Pass by Values
    swapx(a, b); // Actual Parameters

    printf("In the Caller:\na = %d b = %d\n", a, b);

    return 0;
}

// Swap functions that swaps
// two values
void swapx(int x, int y) // Formal Parameters// x=10, y=20
{
    int t;

    t = x; // t=10;
    x = y; // x=20;
    y = t; // y=10;

    printf("Inside Function:\nx = %d y = %d\n", x, y);
}