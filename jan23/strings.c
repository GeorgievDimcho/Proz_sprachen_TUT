#include <stdio.h>

int main()
{
    char full_text[40]="78938651464 330027329";
    char changeWith = '0';
    char searched_element[2] = "33";
    // 
    int i=0;
    int search_counter=0;
    int j=0;
    while(1) {
        //*ptr
        if(full_text[i] == '\0'){
            break;
        }
        if(full_text[i] == searched_element[j]) {
            if(full_text[i+1]==searched_element[j+1])
            {
                search_counter++;
            }
            //search_counter++;
            //full_text[i] = changeWith;
        }
        printf("%c ", full_text[i]);
        i++;
    }
    printf("the character %c was found %d times.", searched_element, search_counter);
    

    return 0;
}