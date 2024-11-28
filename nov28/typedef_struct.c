#include <stdio.h>

// Defining the structure
struct Student
{
    char name[50];
    int age;
    float gpa;
    int *p;
};

// Creating a typedef for the struct
typedef struct Student St;

int main()
{
    // Declaring a variable using the typedef
    // struct Student student1;
    St student1;
    St *student2 = (St *)malloc(sizeof(St));
    //(*student2).age = 100;
    // error is no malloc on line 20
    student2->age = 100;

    // Assigning values to the struct members
    snprintf(student1.name, sizeof(student1.name), "Ram");
    student1.age = 20;
    student1.gpa = 9.5;

    /*
        accountp->account_number;

is much more concise than

(*accountp).account_number;

    */
    // student1.p->&age;

    // Displaying the information of a student
    printf("Student Information:\n");
    printf("Name: %s\n", student1.name);
    printf("Age2: %d\n", student2->age);
    printf("GPA: %.2f\n", student1.gpa);

    return 0;
}