void bubbleSort(struct Node* head) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    // Überprüfen, ob die Liste leer ist
    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Werte tauschen
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // Letzter Knoten ist bereits sortiert
    } while (swapped);
}