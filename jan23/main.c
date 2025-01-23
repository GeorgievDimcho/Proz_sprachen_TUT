#include <stdio.h>


struct Person {
    int name;
    struct Person *next;
};
int min;
typedef struct Person Person;


Person *deletePlayer(Person* head, int id) {
   Person* current = head;
    Person* prev = NULL;

    while (current != NULL)
    {
        //printf("\nPlayer %d - Ice time %d - Penalties %d", temp->id, temp->eiszeit, temp->strafen);
        if(current->name == id) {
            //return temp;
            if(prev == NULL) {
                head=current->next;
            } else {
                prev->next=current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;

}

Person *add(Person *head, int name)
{
    // pointer = (int/struct) malloc(wie viel?)
    Person *newPlayer = (Person *)malloc(sizeof(Person));
    // Person *newPlayer = (Person *)malloc(9);
    newPlayer->name = name;
    newPlayer->next = head;
    return newPlayer;
}
Person * sort(Person *head)
{
    Person *current = head; // tmp
    while (current != NULL) // =! null
    {
        //printf("%d ", current->name);
        // current->name
        // 2>1
        if(min>current->name) {
            // platz tauschen
            //head=add(current,current->name); // add infront
            head=deletePlayer(current,current->name);
            head=add(current,current->name);
            //min=current->name;
        }
        current = current->next; // arr[4] -> arr[5]
    }
    return head;
};
void bubbleSort(Person* head) {
    int swapped;
    Person* ptr1;
    Person* lptr = NULL;

    // Überprüfen, ob die Liste leer ist
    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            // aufsteigend oder
            if (ptr1->name < ptr1->next->name) {
                // Werte tauschen
                int temp = ptr1->name;
                ptr1->name = ptr1->next->name;
                ptr1->next->name = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // Letzter Knoten ist bereits sortiert
    } while (swapped);
}
void printList(Person *head)
{
    Person *current = head; // tmp
    while (current != NULL) // =! null
    {
        printf("%d ", current->name);
        current = current->next; // arr[4] -> arr[5]
    }
    printf("\n");
};





int main() 
{
    //unsorted 2,1,4
    // sortet  1,2,4
    // algorithm: geht durch und min. falls nicht head, löschen, addFirst
    Person * unsorted_linked_list=NULL;
    // head von linked list = NULL
    unsorted_linked_list=add(unsorted_linked_list,4);
    
    // min = 4
    // head von linked list = Linked_list with value 4, zeigt to NULL
    unsorted_linked_list=add(unsorted_linked_list,1);
    // head von linked list = Linked_list with value 1, zeigt to Linked_list with value 4
    unsorted_linked_list=add(unsorted_linked_list,2);
    unsorted_linked_list=add(unsorted_linked_list,22);
    unsorted_linked_list=add(unsorted_linked_list,444);
    min = unsorted_linked_list->name; // min=head.name
    printList(unsorted_linked_list);
    //unsorted_linked_list=deletePlayer(unsorted_linked_list,1);
    bubbleSort(unsorted_linked_list);
    printf("Sorted: \n");
    printList(unsorted_linked_list);

   // printf("aaa\n");
    return 0;
}

//
