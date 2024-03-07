#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to rotate the doubly linked list by N nodes
void rotateByN(struct Node** head, int N) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Calculate the length of the linked list
    int length = 0;
    struct Node* temp = *head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // Calculate effective rotation value
    int effectiveRotation = N % length;
    
    // If effective rotation is 0, the list remains unchanged
    if (effectiveRotation == 0) {
        printf("List remains unchanged.\n");
        return;
    }

    // Move to the node at position length - effective_rotation
    temp = *head;
    for (int i = 1; i < length - effectiveRotation; i++) {
        temp = temp->next;
    }

    // Break the list at this position and make it circular
    struct Node* newHead = temp->next;
    temp->next = NULL;
    newHead->prev = NULL;

    // Update the head and tail pointers
    struct Node* tail = newHead;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = *head;
    (*head)->prev = tail;
    *head = newHead;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the doubly linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    // Print the original doubly linked list
    printList(head);

    // Rotate the doubly linked list by N nodes
    int N;
    printf("Enter the number of nodes to rotate by: ");
    scanf("%d", &N);
    rotateByN(&head, N);

    // Print the rotated doubly linked list
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
