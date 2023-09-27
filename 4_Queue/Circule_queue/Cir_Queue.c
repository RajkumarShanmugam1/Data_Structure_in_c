/*Implement the Circular Queue
 * */

#include<stdio.h>
#include<stdlib.h>

struct queue {
    int rear;
    int front;
    int size;
    int *arr;
};

int isEmpty(struct queue*);
int isFull(struct queue*);
void display(struct queue*);
int checkStatus(struct queue*);
void enqueue(struct queue*, int);
void dequeue(struct queue*);
int frontt(struct queue*);

int main() {
    int ch, n;

    struct queue *q1 = (struct queue*)malloc(sizeof(struct queue));
    printf("Enter the size of queue: ");
    scanf("%d", &q1->size);
    // Initialize front and rear here
    q1->front = q1->rear = -1;
    // Allocate memory for the queue array
    q1->arr = (int*)malloc(q1->size * sizeof(int));

    do {
        printf("\nMenu:\n\t1. Display\n\t2. Check Capacity\n\t3. Enqueue\n\t4. Dequeue\n\t5. Front\n\t6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                display(q1);
                break;
            case 2:
                n = checkStatus(q1);
                if (n == 0)
                    printf("Queue Empty\n");
                else if (n == 1)
                    printf("Queue Full\n");
                else
                    printf("Queue has some elements\n");
                printf("Number of elements: %d\n", ((q1->rear - q1->front + q1->size) % q1->size)+1);
                break;
            case 3:
                printf("Enter your number: ");
                scanf("%d", &n);
                enqueue(q1, n);
                break;
            case 4:
                dequeue(q1);
                break;
            case 5:
                n = frontt(q1);
                if (n == -1)
                    printf("Queue is empty\n");
                else
                    printf("Front element: %d\n", n);
                break;
            case 6:
                printf("Queue closed\n");
                return 0;
        }
    } while (1);
}

/* Return status of queue empty */
int isEmpty(struct queue *q1) {
    return (q1->front == -1 && q1->rear == -1);
}

/* Return status of queue full */
int isFull(struct queue *q1) {
    // Use modulo operator to check if the next position is the front
    return ((q1->rear + 1) % q1->size == q1->front);
}

/* Return status of queue */
int checkStatus(struct queue *q1) {
    if (isEmpty(q1)){
        return 0;
    }
    else if (isFull(q1)){
        return 1;
    }
    else{
        return 2;
    }
}

/* Insert value in rear of the queue */
void enqueue(struct queue *q1, int a) {
    if (isFull(q1)) {
        printf("Queue is full, cannot enqueue\n");
    }
    else{
        if (isEmpty(q1)){
            q1->front = q1->rear = 0;
	}
        else{
            q1->rear = (q1->rear + 1) % q1->size;
	}
        q1->arr[q1->rear] = a;
        printf("%d Successfully inserted\n", a);
    }
}

/* Remove front of the value in queue */
void dequeue(struct queue *q1) {
    if (isEmpty(q1)) {
        printf("Queue is empty, cannot dequeue\n");
    }
    else {
        printf("%d Successfully dequeued\n", q1->arr[q1->front]);
        if (q1->front == q1->rear){
            q1->front = q1->rear = -1;
	}
        else{
            q1->front = (q1->front + 1) % q1->size;
	}
    }
}

int frontt(struct queue *q1) {
    if (isEmpty(q1))
        return -1;
    else
        return q1->arr[q1->front];
}

void display(struct queue *q1) {
    if (isEmpty(q1))
        printf("Queue is empty\n");
    else {
        int i = q1->front;
        printf("|");
        
        // Traverse the circular queue correctly
        while (i != q1->rear) {
            printf(" %d |", q1->arr[i]);
            i = (i + 1) % q1->size;
        }
        printf(" %d |\n", q1->arr[q1->rear]);
    }
}