/*
 * Linked list operations
 * */

#include"ll.h"

int main()
{
   struct node* head = NULL;
   int ch = 0;
   int n,pos;
   while(ch != 11){
      printf("\nMenu :\n");
      printf("  1.Size of linked list\n");
      printf("  2.Insert At first\n");
      printf("  3.Insert At Last\n");
      printf("  4.Insert At Position\n");
      printf("  5.Delete At first\n");
      printf("  6.Delete At Last\n");
      printf("  7.Delete At position\n");
      printf("  8.Delete At position from reverse\n");
      printf("  9.sort\n");
      printf("  10.Display\n");
      printf("  11.DisplayPosition\n");
      printf("  12.Exit\n");
      printf("Enter the option : ");
      scanf("%d",&ch);
      switch(ch){
         case 1:
            n = size(head);
            if(n==0){
               printf("Linked list is empty\n");
	    }
	    else{
               printf("Size : %d\n",n);
	    }
	    break;
	 case 2:
	    printf("Enter one number : ");
	    scanf("%d",&n);
	    n = insertAtFirst(&head,n);
	    if(n==1){
               printf("Insertion Success\n");
	    }
	    else{
               printf("Insertion Fail\n");
	    }
	    break;
	 case 3:
	    printf("Enter one number : ");
	    scanf("%d",&n);
	    n = insertAtLast(&head,n);
	    if(n==1){
               printf("Insertion Success\n");
	    }
	    else{
               printf("Insertion Fail\n");
	    }
	    break;
	 case 4:
	    printf("Enter one number : ");
	    scanf("%d",&n);
	    printf("Enter Position   : ");
	    scanf("%d",&pos);
	    n = insertAtPosition(&head,n,pos);
	    if(n==1){
               printf("Insertion Success\n");
	    }
	    else if(n==-1){
               printf("Linkedlist is empty\nYou have only insert at first Position\n");
               printf("Insertion Fail\n");
	    }
	    else if(n==-2){
               printf("Enter 1 or more than 1\n");
               printf("Insertion Fail\n");
	    }
	    else if(n==-3){
               printf("Max size is %d\n",size(head));
               printf("Insertion Fail\n");
	    }
	    break;
	 case 5:
	    n = deleteAtFirst(&head);
	    if(n!=-1){
               printf("%d is Deletion Success\n",n);
	    }
	    else{
               printf("Deletion Fail\nLinked list empty\n");
	    }
	    break;
	 case 6:
	    n = deleteAtLast(&head);
	    if(n!=-1){
               printf("%d is Deletion Success\n",n);
	    }
	    else{
               printf("Deletion Fail\nLinked list empty\n");
	    }
	    break;
	 case 7:
            printf("Enter Position   : ");
            scanf("%d",&pos);
            n = deleteAtPosition(&head,pos);
            if(n==1){
               printf("Deletion Success\n");
            }
            else if(n==-1){
               printf("Linkedlist is empty\n");
               printf("Deletion Fail\n");
            }
            else if(n==-2){
               printf("Enter 1 or more than 1\n");
               printf("Deletion Fail\n");
            }
            else if(n==-3){
               printf("Max size is %d\nPlease enter position 1\n",size(head));
               printf("Deletion Fail\n");
            }
            break;
         case 8:
            printf("Enter Position   : ");
            scanf("%d",&pos);
            n = deleteAtPosition(&head,pos);
            if(n==1){
               printf("Deletion Success\n");
            }
            else if(n==-1){
               printf("Linkedlist is empty\n");
               printf("Deletion Fail\n");
            }
            else if(n==-2){
               printf("Enter 1 or more than 1\n");
               printf("Deletion Fail\n");
            }
            else if(n==-3){
               printf("Max size is %d\nPlease enter position 1\n",size(head));
               printf("Deletion Fail\n");
            }
            break;
	 case 9:
	    sort(head);
	    printf("Sorted is success\n");
	    break;
	 case 10:
	    display(head);
	    break;
	 case 12:
	    printf("Thank you!!!\n");
	    break;
	 default:
	    printf("Enter valid option");
	    break;
      }
   }
}
