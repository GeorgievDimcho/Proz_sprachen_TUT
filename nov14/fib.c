#include <stdio.h>
int prev1 = 1;
int prev2 = 0;
int last_number = 0;
void printFib(int n)
{

    // If the number of terms is smaller than 1
    if (n < 2)
    {
        printf("last_num: %d\n", last_number);
        // printf("Invalid Number of terms\n");
        return;
    }

    // First two terms of the series

    // for loop that prints n terms of fibonacci series

    // for (int i = 1; i <= n; i++) {

    // Print current term and update previous terms
    // if (i > 2) {
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
    last_number = curr;
    printf("%d ", curr);
    /*
}
else if (i == 1)
    printf("%d ", prev2);
else (i == 2)
    printf("%d ", prev1);
    */
    printFib(n - 1);
    //}
}

int main()
{
    int n = 10;

    // Printing first n fibonacci terms
    printFib(n);
    return 0;
}