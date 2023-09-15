/*Implement the queue
 * */

#include<stdio.h>
#include<stdlib.h>

struct queue{
   int rear;
   int front;
   int size;
   int *arr;
};

int isEmpty(struct queue*);
int isFull(struct queue*);
void display(struct queue*);
int checkStatus(struct queue*);
void enqueue(struct queue*,int);
void dequeue(struct queue*);
int frontt(struct queue*);

int main(){
   int ch,n;
   int size;
   
   /* create the queue object */
   struct queue *q1 = (struct queue*)malloc(1*sizeof(struct queue));
   printf("Enter the size of queue : ");
   scanf("%d",&q1->size);			// size of queue 
   q1->front = -1;				// Front and rear os -1
   q1->rear = -1;
   q1->arr = (int*)malloc(q1->size*sizeof(int)); // Allocate the memory space of array in queue
   do{
      printf("\nMenu:\n\t1 . Display\n\t2 . Check Capacity\n\t3 . Enqueue\n\t4 . Dequeue\n\t5 . Front\n\t6 . Exit\n");
      printf("Enter option : ");
      scanf("%d",&ch);
      switch(ch){
         case 1:
	    display(q1);
	    break;
	 case 2:
	    n = checkStatus(q1);
	    if(n == 0)
		printf("Queue Empty\n");
	    else if(n == 1)
		printf("Queue full\n");
	    else
		printf("Queue have some elements\n");
	    printf("Number of elements : %d\n",q1->rear-q1->front);
	    break;
	 case 3:
	    printf("Enter your number : ");
	    scanf("%d",&n);
	    enqueue(q1,n);
	    break;
	 case 4:
	    dequeue(q1);
	    break;
	 case 5:
	    n = frontt(q1);
	    if(n==-1)
		printf("Queue is empty\n");
	    else
		printf("rear element : %d\n",n);
	    break;
	 case 6:
	    printf("Queue closed\n");
	    return 0;
     }
   }while(1);
}

/* Return status of queue empty */
int isEmpty(struct queue *q1){
    if(q1->rear == -1 && q1->front == -1)
	return 1;
    else
	return 0;
}

/* Return status of queue full */
int isFull(struct queue *q1){
    if(q1->rear == q1->size)
	return 1;
    else if(q1->front > q1->rear)
	return 1;
    else
	return 0;
}

/* Check the status of queue full and empty */
int checkStatus(struct queue *q1){
    if(isEmpty(q1) == 1)
	return 0;
    else if(isFull(q1) == 1)
	return 1;
    else
	return 2;
}

/* Insert value in rear of the queue */
void enqueue(struct queue *q1,int a){
    if(isFull(q1) == 0){
	if(isEmpty(q1) == 1)
	    q1->rear = q1->front = 0;
	q1->arr[q1->rear++] = a;
	printf("Successfully inserted\n");
    }
    else
	printf("Queue is full, So cannot enqueue\n");
    //return q1;
}

/* Remove front of the value in queue */
void dequeue(struct queue *q1){
    if(isEmpty(q1) == 0){
	q1->arr[q1->front++] = 0;
	printf("Success fully dequeueped\n");
    }
    else
	printf("Queue is Empty, So cannot dequeue\n");
    if(q1->front >= q1->rear)
	q1->front = q1->rear = -1;
    //return q1;
}

/* Return front of the value in queue */
int frontt(struct queue *q1){
    if(isEmpty(q1) == 0)
	return q1->arr[q1->front];
    else
	return -1;
}

/* Display Data in queue view */
void display(struct queue *q1){
    if(isEmpty(q1) == 1)
        printf("Queue is empty\n");
    else{
	printf("|");
        for(int i=q1->front;i<q1->rear;i++){
		printf(" %d ",q1->arr[i]);
		printf("|");
	}
	printf("\n");
    }
}
