// An example program to demonstrate working
// of enum in C
#include <stdio.h>

enum week
{
    Mon, // 0
    Tue, // 1
    Wed, // 2
    Thur,
    Fri,
    Sat,
    Sun
};

int main()
{
    enum week day;
    day = Sun;
    printf("Position in enum: %d\n", day);
    return 0;
}
