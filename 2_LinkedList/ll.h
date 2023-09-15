/*
Linked list operations
*/

#include<stdio.h>
#include<stdlib.h>
#define ZERO 0
#define TWO 2
#define FIVE 5

/*Create the node for Linkedlist*/
struct node
{
	int data;
	struct node* next;
};

int insertAtFirst(struct node**,int);		/*Insert data at first into the linkedlist*/
int insertAtLast(struct node**,int);		/*Insert data at Last into the linkedlist*/
int insertAtPosition(struct node**,int,int);	/*Insert data at Position into the linkedlist*/
int deleteAtFirst(struct node**);		/*Delete data at first from linkedlist*/
int deleteAtLast(struct node**);		/*Delete data at Last from linkedlist*/
int deleteAtPosition(struct node**,int);	/*Delete data at specified position from linkedlist*/
int deleteAtpositionRev(struct node**,int);	/*Delete data at position from reverse on linkedlist*/
void display(struct node*);			/*Display Entire data in linked list*/
void display1(struct node*,int);		/*Display the value at the particular position*/
void sort(struct node*);			/*Find the lenght of linked list*/
int size(struct node*);				/*Sort the linked list data using bubble sort*/
