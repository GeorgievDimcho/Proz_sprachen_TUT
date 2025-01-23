#include <stdio.h>

int main()
{
    int full_text[40];
    for(int a=0;a<=39;a++) {
    full_text[a]=-3456;
 }

    full_text[0]=10;
     full_text[1]=4;
        
      full_text[2]=100;
 full_text[3]=110;
 full_text[4]=3;
 full_text[5]=2;
  full_text[6]=3;

 
 
    int searched_element = 3;
    int i=0;
    int search_counter=0;
     while(1) {
        //*ptr
        if(full_text[i] == -3456){
            break;
        }
         printf("element %d, value:%d\n",i,full_text[i]);
         i++;
 }
 i=0;
    while(1) {
        //*ptr
        if(full_text[i] == -3456){
            break;
        }
        if(full_text[i] == searched_element) {
            search_counter++;
        }
        //printf("%c ", full_text[i]);
        i++;
    }
    printf("the character %d was found %d times.", searched_element, search_counter);
    

    return 0;
}