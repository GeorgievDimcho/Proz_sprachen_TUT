#include <stdio.h>

int first_length, second_length,third_length;
int first_width, second_width,third_width;
int first_area, second_area,third_area;
int length, width;
double average_area, devisionFactor;

void calculateTopArea(int *first_area)
{
    first_area=first_length*first_width;
    second_area=second_length*second_width;
    third_area=third_length*third_width;
    devisionFactor = 1.0;
    printf("\nBiggest areas");
    if(first_area != 0)
    {
        printf("\nArea: %d",first_area);
    }
    if(second_area != 0)
    {
        devisionFactor++;
        printf("\nArea: %d",second_area);
    }
    if(third_area != 0)
    {
        devisionFactor++;
        printf("\nArea: %d",third_area);
    }

    average_area = (first_area + second_area + third_area) / devisionFactor;
    printf("\nAverage area: %.2f", average_area);
}

void calculateN()
{
    printf("\nEnter length,width: ");
    scanf(" %d,%d",&length,&width);

    if(length>0&&width>0)
    {
        printf("\nArea: %d", length*width);
    }
    else
    {
        printf("\nInvalid length or width");
    }


    if(length>first_length)
    {
        third_length = second_length;
        second_length = first_length;
        first_length = length;
        printf("\nNew greatest length: %d",first_length);

    }
    else if(length> second_length)
    {
        third_length=second_length;
        second_length=length;
        printf("\nNew second greatest length: %d",second_length);
    }
    else if (length > third_length)
    {
        third_length = length;
        printf("\nNew third greatest length: %d",third_length);
    }

    if(width>first_width)
    {
        third_width = second_width;
        second_width = first_width;
        first_width= width;
        printf("\nNew greatest width: %d",first_width);

    }
    else if(width> second_width)
    {
        third_width=second_width;
        second_width=width;
        printf("\nNew second greatest width: %d",second_width);
    }
    else if (width > third_width)
    {
        third_width = width;
        printf("\nNew third greatest width: %d",third_width);
    }
}

void calculateT()
{
    if(first_length==0&&first_width==0)
    {
        printf("\nBiggest areas");
        printf("\nNo areas yet");

    }
    else
    {
        calculateTopArea();
    }

}

int main()
{
    char choice;
    while(1)
    {
        printf("\nEnter n, t OR x: ");
        scanf(" %c",&choice);
        if(choice == 'n')
        {
            calculateN();
        }
        if (choice == 't')
        {
            calculateT();
        }
        if(choice == 'x')
        {
            calculateT();
            break;
        }
    }

    return 0;
}
