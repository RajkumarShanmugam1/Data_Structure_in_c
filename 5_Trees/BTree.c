/* Binary Tree Implementation
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *left;
   struct node *right;
};

struct node* create();
void pre_order(struct node*);
void in_order(struct node*);
void post_order(struct node*);
void display(struct node*,int);

int main(){
   struct node *root;
   root = create();
   printf("\nPre  order : ");
   pre_order(root);
   printf("\nIn   order : ");
   in_order(root);
   printf("\nPost order : ");
   post_order(root);
   printf("\n\nTree : \n");
   display(root,0);
   printf("\nThank you !!!\n");
}

/* Create a node */
struct node* create(){
   struct node *newNode = NULL;
   int data1;
   
   printf("Enter the data [ -1 for no node ] : ");
   scanf("%d",&data1);
   
   /* new node was not created */
   if(data1 == -1){
      return newNode;
   }
   
   /* NewNode creation */
   newNode = (struct node*)malloc(sizeof(struct node));
   
   /* data of new node */
   newNode->data = data1;
   
   /* Left Node creation */
   printf("Left  node of %d\n",data1);
   newNode->left = create();
   
   /* Right Node creation */
   printf("Right node of %d\n",data1);
   newNode->right = create();
   
   return newNode;
}

/*Display based on traversel */
/* PRE order display */
void pre_order(struct node *node1){
   /* Root  Left  Right */
   if(node1 == NULL ){
      return;
   }
   printf("%d\t",node1->data);
   pre_order(node1->left);
   pre_order(node1->right);
}

/* IN order display */
void in_order(struct node *node1){
   /* Left Root Right */
   if(node1 == NULL ){
      return;
   }
   in_order(node1->left);
   printf("%d\t",node1->data);
   in_order(node1->right);
}

/* POST order display */
void post_order(struct node *node1){
   /* Left Right Root */
   if(node1 == NULL ){
      return;
   }
   post_order(node1->left);
   post_order(node1->right);
   printf("%d\t",node1->data);
}

/*
Display based on levels
|---->2
2      
|      |---->5
|---->3|
       |---->4
*/
void display(struct node *node1,int level){
   if(node1==NULL){
      return;
   }
   
   display(node1->right,level+1);
   
   if(level!=0){
      for(int i=0;i < level - 1;i++){
         printf("|\t");
      }
      printf("|------>%d\n",node1->data);
   }
   else{
      printf("%d\n",node1->data);
   }
   display(node1->left,level+1);
}
