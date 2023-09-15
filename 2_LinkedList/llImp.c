/*
 * Linked list operations
 * ----------------------
 * Insertion
 * Sorting
 * Display
*/

#include"ll.h"

/*Insert data at first into the linkedlist*/
int insertAtFirst(struct node** head, int v) {
    struct node* newNode;
    /*Create new node*/
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = v;
    newNode->next = NULL;
    
    /* If the linked list is empty */
    if (*head == NULL) {
        *head = newNode;
        return 1; // Successfully inserted into an empty list
    }
    else {
        newNode->next = *head;
        *head = newNode;
        return 1; // Successfully inserted into a non-empty list
    }
}

/*Insert data at first into the linkedlist*/
int insertAtLast(struct node** head, int v) {
    struct node *newNode,*temp;
    /*Create new node*/
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = v;
    newNode->next = NULL;
    
    /* If the linked list is empty */
    if (*head == NULL) {
        *head = newNode;
    }
    else {
	temp = *head;
	while(temp->next != NULL){
           temp = temp->next;
	}
	temp->next = newNode;
    }
    return 1; // Successfully inserted
}

/*Insert data at position into the linkedlist*/
int insertAtPosition(struct node** head, int v,int p) {
    struct node *newNode,*temp;
    /*Create new node*/
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = v;
    newNode->next = NULL;
    
    if(p<=0){ //Enter 1 or more than 1
       return -2;
    }
    else if(p==1){ // Insert First Position
       insertAtFirst(head,v);
    }
    else if(size(*head)+1 == p){ // Insert last position
       insertAtLast(head,v);
    }
    else if(size(*head)+1 < p){ // Insert outbound
       return -3;
    }
    else { // Insert position
	temp = *head;
	for(int i=0;i<p-2;i++) {// From 2 position
           temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
    }
    return 1; // Successfully inserted
}

/*Delete data at first from the linkedlist*/
int deleteAtFirst(struct node** head) {
    int n;
    struct node* oldNode;

    /* If the linked list is empty */
    if (*head == NULL) {
        return -1; // deletion failed in an empty list
    }
    else {
        oldNode = *head;
        n = oldNode->data;
	*head = oldNode -> next;
	free(oldNode);
        return n; // Successfully inserted into a non-empty list
    }
}

/*Delete data at last from the linkedlist*/
int deleteAtLast(struct node** head) {
    int n;
    struct node *temp,*ptr;

    /* If the linked list is empty */
    if (*head == NULL) {
        return -1; // deletion failed in an empty list
    }
    if(size(*head)==1){ //Only one
        return deleteAtFirst(head);
    }
    else {
        temp = *head;
	while(temp->next->next!=NULL){
           temp = temp->next;
	}
	n = temp->next->data;
	ptr = temp->next;
	temp->next = NULL;
	free(ptr);
        return n; // Successfully inserted into a non-empty list
    }
}

/*Delete data at position from the linkedlist*/
int deleteAtPosition(struct node** head,int p) {
    int n;
    struct node *temp,*ptr;   
    
    if(*head == NULL){ /* If the linked list is empty */
        return -1; // deletion failed in an empty list
    }
    else if(p<=0){ // Enter 1 or more 1
       return -2;
    }
    else if(p==1){ // delete at first
       n = deleteAtFirst(head);
    }
    else if (size(*head) == p){ // Delete at last
       n = deleteAtLast(head);
    }
    else if (size(*head) < p){ // out of bound
       return -3;
    }
    else{ // Delete position
       temp = *head;
       for(int i=0;i<p-2;i++) {// From 2 position
          temp = temp->next;   
       }
       ptr = temp->next;
       n = ptr->data;
       temp->next = temp->next->next;
       free(ptr);
    }
    return n; // Successfully inserted into a non-empty list
}

/*Delete data at position from the linkedlist*/
int deleteAtPositionRev(struct node** head,int p) {
    int n;
    struct node *temp,*ptr;   
    
    if(*head == NULL){ /* If the linked list is empty */
        return -1; // deletion failed in an empty list
    }
    else if(p<=0){ // Enter 1 or more 1
       return -2;
    }
    else if(p==1){ // delete at first
       n = deleteAtFirst(head);
    }
    else if (size(*head) == p){ // Delete at last
       n = deleteAtLast(head);
    }
    else if (size(*head) < p){ // out of bound
       return -3;
    }
    else{ // Delete position
       temp = *head;
       ptr = *head;
       for(int i=0;i<p;i++){
          temp = temp->next;
       }
       while(temp->next!=NULL){
          temp = temp->next;
          ptr = ptr->next;
          //printf("%d\n",ptr);
       }
       n = ptr->next->data;
       temp = ptr->next;
       ptr->next = ptr->next->next;
       free(temp);
    }
    return n; // Successfully inserted into a non-empty list
}

/*Display Entire data in linked list*/
void display(struct node* head){
	/*If the linkedlist is empty or not*/
	if(head==NULL){
		printf("Linked List is Empty\n");
		return;
	}
	/*Linked list datas*/
        printf("LinkedList: ");
	struct node* ptr = head;
	/*If Linkedlist have some elements */
	while(ptr!=NULL){ 
		printf("%d ",ptr->data);
		/*Move forward in linkedlist*/
		ptr = ptr->next;
	}
    printf("\n");
}

/*Display the value at the particular position*/
void display1(struct node* head,int n){
	int count = 0;
	struct node* ptr = head;
	/*If lInked list is empty*/
	if(head==NULL){
		printf("Linked List is Empty\n");
		return;
	}
	/*Check the given position is valid or not*/
	if(n<=size(head)){
		printf("Your %d position data is ",n);
		while(ptr!=NULL){
			/*Move forward in linkedlist*/
			ptr = ptr->next;
			count++;
			if(count==n-1){/*Check and retrive the position of element*/
				printf("%d\n",ptr->data);
				break;
			}
		}
	}
}

/*Find the lenght of linked list*/
int size(struct node *head){
	int s = 0;
	struct node* ptr = head;
	/*Checking the end point of linked list*/
	while(ptr!=NULL){
		/*Move forward in linked list*/
		ptr = ptr->next;
		/*Increment the count for finding the lenght of linkedlist*/
		s++;
	}
	return s;
}

/*Sort the linked list data using bubble sort*/
void sort(struct node *head){ 
    int check, temp;
    struct node *ptr1 = head; 
    /*If linked list is empty or not*/
    if(head == NULL) 
        return;
    /*Bubble sort*/
    do{ 
        check = 0; 
        ptr1 = head;
	/*cheking the pointer whether reached at the end of the linked list*/
        while (ptr1->next != NULL){ 
	    /*checking the previous data is greater then next data*/
            if (ptr1->data > ptr1->next->data){
                /*Next 3 statements for swap to data*/ 
                temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
		/*Activate the swap flag*/
                check = 1; 
            }
	    ptr1 = ptr1->next;/*Move forward in linked list*/
        }
    } 
    while (check);/*Checking the swap is there or not*/
}
