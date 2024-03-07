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

// Function to sort the elements of the queue in ascending order using selection sort
void sortQueue(struct Queue* queue) {
    int i, j, minIndex, temp;
    int size = queue->size;
    for (i = 0; i < size - 1; ++i) {
        minIndex = i;
        for (j = i + 1; j < size; ++j) {
            if (queue->array[j] < queue->array[minIndex])
                minIndex = j;
        }
        // Swap elements
        temp = queue->array[minIndex];
        queue->array[minIndex] = queue->array[i];
        queue->array[i] = temp;
    }
}

// Function to print the elements of the queue
void printQueue(struct Queue* queue) {
    int i;
    for (i = 0; i < queue->size; ++i)
        printf("%d ", queue->array[i]);
    printf("\n");
}

// Main function
int main() {
    struct Queue* queue = createQueue(10);

    // Enqueue elements into the queue
    enqueue(queue, 6);
    enqueue(queue, 3);
    enqueue(queue, 9);
    enqueue(queue, 2);
    enqueue(queue, 7);

    printf("Original queue: ");
    printQueue(queue);

    // Sort the queue
    sortQueue(queue);

    printf("Queue after sorting: ");
    printQueue(queue);

    return 0;
}
