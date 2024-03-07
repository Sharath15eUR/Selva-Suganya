#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in sorted order in a doubly linked list
void insertSorted(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If the list is empty or the data of the first node is greater than the new data,
    // insert the new node at the beginning
    if (*head == NULL || (*head)->data > data) {
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Traverse the list to find the position to insert the new node
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // Insert the new node between current and current->next
    newNode->next = current->next;
    if (current->next != NULL)
        current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Inserting elements into the sorted doubly linked list
    insertSorted(&head, 2);
    insertSorted(&head, 5);
    insertSorted(&head, 7);
    insertSorted(&head, 9);

    printf("Original sorted doubly linked list: ");
    printList(head);

    // Inserting a value in sorted way
    int valueToInsert = 6;
    printf("Inserting %d in sorted way...\n", valueToInsert);
    insertSorted(&head, valueToInsert);

    printf("Doubly linked list after insertion: ");
    printList(head);

    return 0;
}
