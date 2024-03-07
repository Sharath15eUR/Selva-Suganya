#include <stdio.h>
#include <stdlib.h>

// Queue structure
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a new queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to count the number of elements in the queue
int countElements(struct Queue* queue) {
    return queue->size;
}

// Function to print the elements of the queue
void printQueue(struct Queue* queue) {
    int i;
    for (i = 0; i < queue->size; ++i)
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    printf("\n");
}

// Main function
int main() {
    struct Queue* queue = createQueue(5);

    printf("Initialize a queue!\n");

    // Check if the queue is empty
    if (isEmpty(queue)) {
        printf("Check the queue is empty or not? Yes\n");
    } else {
        printf("Check the queue is empty or not? No\n");
    }

    // Print the number of elements in the queue
    printf("Number of elements in queue: %d\n", countElements(queue));

    // Insert elements into the queue
    printf("\nInsert some elements into the queue:\n");
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Queue elements are: ");
    printQueue(queue);

    // Print the number of elements in the queue
    printf("Number of elements in queue: %d\n", countElements(queue));

    // Delete two elements from the queue
    printf("\nDelete two elements from the said queue:\n");
    dequeue(queue);
    dequeue(queue);

    printf("Queue elements are: ");
    printQueue(queue);

    // Print the number of elements in the queue
    printf("Number of elements in queue: %d\n", countElements(queue));

    // Insert another element into the queue
    printf("\nInsert another element into the queue:\n");
    enqueue(queue, 4);

    printf("Queue elements are: ");
    printQueue(queue);

    // Print the number of elements in the queue
    printf("Number of elements in the queue: %d\n", countElements(queue));

    return 0;
}
