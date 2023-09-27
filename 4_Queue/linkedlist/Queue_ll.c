/*Implement the queue in linked list
 * */
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;         // Data stored in the node
    struct Node* next; // Pointer to the next node
};

// Structure for the queue
struct Queue {
    struct Node* front; // Pointer to the front of the queue
    struct Node* rear;  // Pointer to the rear of the queue
};

int isEmpty(struct Queue*);
void display(struct Queue*);
void enqueue(struct Queue*,int);
void dequeue(struct Queue*);
int front(struct Queue*);

int main() {
    struct Queue q1; // Create a queue
    q1.front = q1.rear = NULL; // Initialize front and rear pointers
    int choice, value;
    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Display Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Front Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(&q1);
                break;
            case 2:
                printf("Enter a value : ");
                scanf("%d", &value);
                enqueue(&q1, value);
                break;
            case 3:
                dequeue(&q1);
                break;
            case 4:
                value = front(&q1);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 5:
                // Exit the program
                printf("Thanks!!!\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Display the elements of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        struct Node* current = q->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Add an element to the rear of queue
void enqueue(struct Queue* q, int value) {
    // Create a new node to hold the data
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } 
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d\n", value);
}

// Remove an element from the front of queue
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;
    
    free(temp);
    printf("Dequeued\n");
}

// Retrieve the front element of the queue
int front(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}