"/* Implement the stack in Linked list
 * FILO
 * */

#include <stdio.h>
#include <stdlib.h>

// Structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the stack, which uses a linked list
struct Stack {
    struct Node* top; // The top points to the top element of the stack
};

struct Node* createNode(int);
int isEmpty(struct Stack*) ;
void push(struct Stack*,int);
int pop(struct Stack*);
int peek(struct Stack*);
void display(struct Stack*) ;

int main() {
    struct Stack s1;
    s1.top = NULL; // Initialize an empty stack

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push: ");
                scanf("%d", &value);
                push(&s1, value);
                break;
            case 2:
                printf("Popped value: %d\n", pop(&s1));
                break;
            case 3:
                printf("Top of the stack: %d\n", peek(&s1));
                break;
            case 4:
                display(&s1);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push a new element onto the stack
void push(struct Stack* stack, int data) { // Insert at first in linked list
    struct Node* newNode = createNode(data);
    newNode->next = stack->top; // Make the new node the new top
    stack->top = newNode;
}

// Function to pop the top element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    
    /* Delete at first in linked list */
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next; // Update the top to the next element
    free(temp); // Free the memory of the popped node
    return data;
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack->top->data;
}

// Function to display the elements in the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        struct Node* current = stack->top;
        printf("Stack elements: ");
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
