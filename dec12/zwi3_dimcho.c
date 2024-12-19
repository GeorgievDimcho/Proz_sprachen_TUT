#include <stdio.h>
#include <stdlib.h>

struct Spieler {
    int strafen; // 3*4+4 byte
    int eiszeit;
    int id;
    struct Spieler *next;
    //
};

void printPlayer(struct Spieler* head)
{
    struct Spieler* temp = head;

    while (temp != NULL)
    {
        printf("\nPlayer %d - Ice time %d - Penalties %d", temp->id, temp->eiszeit, temp->strafen);
        temp = temp->next;
    }
};

struct Spieler* searchPlayer(struct Spieler* head, int id)
{
    struct Spieler* temp = head;

    while (temp != NULL)
    {
        //printf("\nPlayer %d - Ice time %d - Penalties %d", temp->id, temp->eiszeit, temp->strafen);
        if(temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
};

struct Spieler *addBefore(int id, struct Spieler *head)
{
    struct Spieler *newHead = (struct Spieler *)malloc(sizeof(struct Spieler));
    newHead->id = id;
    if(id >= 6) {
        newHead->eiszeit=0;
    } else {
        newHead->eiszeit=1;
    }
    newHead->strafen=0;
    newHead->next = head;
    return newHead;
}
                                    // EIS                  //  Existier Bank
struct Spieler *add(struct Spieler *head, struct Spieler *newPlayer)
{
    struct Spieler *newHead = (struct Spieler *)malloc(sizeof(struct Spieler));
    newHead->id = newPlayer->id;
    newHead->strafen=newPlayer->strafen;
    // if()
    newHead->eiszeit=newPlayer->eiszeit;
    newHead->next = head;
    return newHead;
}

struct Spieler *deletePlayer(struct Spieler * head, int id) {
    struct Spieler* current = head;
    struct Spieler* prev = NULL;

    while (current != NULL)
    {
        //printf("\nPlayer %d - Ice time %d - Penalties %d", temp->id, temp->eiszeit, temp->strafen);
        if(current->id == id) {
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

int main()
{
    struct Spieler * Eis = NULL;
    struct Spieler * Strafbox = NULL;
    struct Spieler * Bank = NULL;
    for(int i = 5; i>=1;i--) {
        Eis = addBefore(i,Eis);
    }
    for(int i = 10; i>=6;i--) {
        Bank = addBefore(i,Bank);
    }
    char input;
    int player_counter = 11;
    while(1) {
        printf("\nEnter c, n, t, p or x: ");
        scanf(" %c", &input);
        if(input == 'c') {

            int inputice,inputbench ;
            printf("\nEnter ice player number: ");
            scanf("%d", &inputice);
            //player *iceP = findPl(iceHead, inputice);
            struct Spieler* foundPlayerEis = searchPlayer(Eis, inputice);
            printf("\nEnter bench player number: ");
            scanf("%d", &inputbench);
            struct Spieler* foundPlayerBank = searchPlayer(Bank, inputbench);
            if(foundPlayerEis!=NULL && foundPlayerBank != NULL) {
                // move player
                Bank = add(Bank, foundPlayerEis);
                // foundPlayerEis delete from EIS
                Eis = deletePlayer(Eis, inputice);
                // Eis=

                Eis=add(Eis, foundPlayerBank);
                Bank=deletePlayer(Bank, inputbench);
            } else {
                printf("ERROR\n");
            }
        } else if (input == 'n') {
            // add new player to bank
            Bank=addBefore(player_counter,Bank);
            player_counter++;
        } else if (input == 'p') {
            int p;
            printf("enter player id: ");
            scanf("%d", &p);
            struct Spieler* foundPlayerEis = searchPlayer(Eis, p);
            if (foundPlayerEis != NULL) {
                Strafbox = add(Strafbox, foundPlayerEis);
                Eis=deletePlayer(Eis, p);
            }

            // strafe
        } else if(input == 't') {
            printf("\nEIS:\n");
            printPlayer(Eis);
            printf("\nBANK:\n");
            printPlayer(Bank);
            printf("\nStrafbox:\n");
            printPlayer(Strafbox);
            // print players
        } else if (input == 'x'){
            break;
        } else {
            printf("Wrong oprion, please enter a valid option!\n");
        }
    }

    return 0;
}

