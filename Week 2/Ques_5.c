#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LENGTH 100

// Define a stack structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a new stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Function to reverse a given string using a stack
void reverseString(char* str) {
    // Create a stack with capacity equal to the length of the string
    struct Stack* stack = createStack(strlen(str));

    // Push each character of the string onto the stack
    for (int i = 0; i < strlen(str); i++) {
        push(stack, str[i]);
    }

    // Pop each character from the stack and store it back into the string
    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(stack);
    }

    // Free the memory allocated for the stack
    free(stack->array);
    free(stack);
}

// Main function
int main() {
    char str[MAX_LENGTH];

    // Input string from the user
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';

    // Reverse the string
    reverseString(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
