#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name;
    struct Person *next;
};

typedef struct Person Person;

void printList(Person *head)
{
    Person *current = head; // tmp
    while (current != NULL) // =! null
    {
        printf("%c ", current->name);
        current = current->next; // arr[4] -> arr[5]
    }
};
int countElements(Person *head) {
    int countEle = 0;
    Person *current = head;
    while (current != NULL)
    {
        countEle++;
        current = current->next;
    }
    return countEle;
};
Person *add(Person *head, char name)
{
    // pointer = (int/struct) malloc(wie viel?)
    Person *newPlayer = (Person *)malloc(sizeof(Person));
    // Person *newPlayer = (Person *)malloc(9);
    newPlayer->name = name;
    newPlayer->next = head;
    return newPlayer;
}
Person* append(Person* head, char new_data) {
    Person* new_node = (Person *)malloc(sizeof(Person));
    //Person* new_node = malloc(sizeof(Person));
    new_node -> name = new_data;
    new_node -> next = NULL;
    if (head == NULL) {
        return new_node;
    }
    Person* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    //free(last);
    return head;
}

Person* deleteHead(Person* head) {
    if (head == NULL)
        return NULL;
    Person* temp = head; //d
    head = head->next; //a
    free(temp); // d
    return head; // a
};
/*
Person *removeFirst(Person *head)
{
    if (head == NULL)
        return head;

    Person *newHead = head->next;
    free(head); // free memory of first node
    return newHead;
};
Person *deleteList(Person *head)
{
    Person *temp = head;
    while (temp != NULL)
    {
        temp = removeFirst(temp);
    }
    return temp;
};
*/

Person *deleteList(Person *head)
{
    Person *current = head;
    while (current != NULL)
    {
        Person *toDelete = current; // 0x9500
        current = current->next; //b
        free(toDelete); //a
        // free(adresse in hex -> 0x9500)
    }
    return NULL;
};

int main()
{
    // Lists
    Person * all=NULL;
    Person * kassa1=NULL;
    Person * kassa2=NULL;
	
    while(42)
    {
        char n;
        printf(": ");
        scanf(" %c", &n);

        if(n == '-') break;

        // Add person
        all = append(all,n);
      
    }

    int run  = 1;
    while(run)
    {
        // Print here
        printf("Personen: %d\n", countElements(all));
        printList(all);
        printf("\nKassa 1: %d\n", countElements(kassa1));
        printList(kassa1);
        printf("\nKassa 2: %d\n", countElements(kassa2));
        printList(kassa2);
        printf("\n");
       

        char c;
        printf(": ");
        scanf(" %c", &c);

        if(c == '-') break;

        switch(c)
        {
        case '-':
            run = 0;
            break;
        case 'a':
            // anstellen
            int elemK1 = countElements(kassa1);
            int elemK2 = countElements(kassa2);
            if(elemK1>elemK2) {
                //add head to kassa 2
                kassa2=append(kassa2,all->name);
                
            } else {
                // add head to kassa 1
                kassa1=append(kassa1,all->name);
            }
            all = deleteHead(all);
            break;
        case '1':
            // kassa1
             kassa1 = deleteHead(kassa1);
            break;
        case '2':
            // kassa2
            kassa2=deleteHead(kassa2);
            break;
        }
    }

    // free list
    all = deleteList(all);
    kassa1=deleteList(kassa1);
    kassa2=deleteList(kassa2);

    return 0;
}