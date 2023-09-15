/*Implement the stack
 * */

#include<stdio.h>
#include<stdlib.h>

struct stack{
   int top;
   int capacity;
   int *arr;
};

int isEmpty(struct stack);
int isFull(struct stack);
void display(struct stack);
int checkStatus(struct stack);
struct stack push(struct stack,int);
struct stack pop(struct stack);
int peek(struct stack);

int main(){
   int ch,n;
   int size;
   
   /* create the stack with values */
   struct stack s1;
   printf("Enter the capacity of stack : ");
   scanf("%d",&s1.capacity);				// Capacity of stack
   s1.top = -1;						// default top value is -1
   s1.arr = (int*)malloc(s1.capacity*sizeof(int));	// Allocate the memory space for array in stack
   
   do{
      printf("\nMenu:\n\t1.Display\n\t2.Check Capacity\n\t3.Push\n\t4.Pop\n\t5.Peek\n\t6.Exit\n");
      printf("Enter option : ");
      scanf("%d",&ch);
      switch(ch){
         case 1:
	    display(s1);
	    break;
	 case 2:
	    n = checkStatus(s1);
	    if(n==0)
		printf("Stack Empty\n");
	    else if(n == 1)
		printf("Stack full\n");
	    else
		printf("Stack have some elements\n");
	    printf("Number of elements : %d\n",s1.top+1);
	    break;
	 case 3:
	    printf("Enter your number : ");
	    scanf("%d",&n);
	    s1 = push(s1,n);
	    break;;
	 case 4:
	    s1 = pop(s1);
	    break;
	 case 5:
	    n = peek(s1);
	    if(n==-1)
		printf("Stack is empty\n");
	    else
		printf("Top element : %d\n",n);
	    break;
	 case 6:
	    printf("Stack closed\n");
	    return 0;
     }
   }while(1);
}

/* Return status of stack empty */
int isEmpty(struct stack s){
    if(s.top == -1)
	return 1;
    else
	return 0;
}

/* Return status of stack full */
int isFull(struct stack s){
    if(s.capacity - 1 == s.top)
	return 1;
    else
	return 0;
}

/* Check the status of stack full and empty */
int checkStatus(struct stack s){
    if(isEmpty(s) == 1)
	return 0;
    else if(isFull(s) == 1)
	return 1;
    else
	return 2;
}

/* Insert value in top of the stack */
struct stack push(struct stack s1,int a){
    if(isFull(s1) == 0){
	s1.arr[++s1.top] = a;
	printf("Successfully inserted\n");
    }
    else
	printf("Stack is full, So cannot push\n");
    return s1;
}

/* Remove top of the value in stack */
struct stack pop(struct stack s1){
    if(isEmpty(s1) == 0){
	s1.arr[s1.top--] = 0;
	printf("Success fully popped\n");
    }
    else
	printf("Stack is Empty, So cannot pop\n");
    return s1;
}

/* Return top of the value in stack */
int peek(struct stack s1){
    if(isEmpty(s1) == 0)
	return s1.arr[s1.top--];
    else
	return -1;
}

/* Display Data in stack view */
void display(struct stack s){
    if(isEmpty(s) == 1)
        printf("Stack is empty\n");
    else{
	printf("----\n");
        for(int i=s.top;i>-1;i--){
		printf(" %d\n",s.arr[i]);
		printf("----\n");
	}
    }
}
