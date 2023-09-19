/* Binary Search Tree Implementation
 * Why BST?
 *    - Binary tree deletion is not possible and hard
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *left;
   struct node *right;
};

struct node* create_node(int);
int insert(struct node**,int);
struct node* delete(struct node**,int);

struct node* find_min(struct node*);
struct node* find_max(struct node*);

int get_height(struct node*);
int max(int,int);

void pre_order(struct node*);
void in_order(struct node*);
void post_order(struct node*);
void display(struct node*,int);


int main(){
   struct node *root,*temp;
   int ch,data,n;
   ch = 0;
   
   while(ch!=7){
      printf("MENU:\n");
      printf("  1.Insertion\n");
      printf("  2.Deletion\n");
      printf("  3.Display\n");
      printf("  4.Traversal Display\n");
      printf("  5.FindMin\n");
      printf("  6.FindMax\n");
      printf("  7.Exit\n");
      printf("Enter one option : ");
      scanf("%d",&ch);
      switch(ch){
         case 1:
            printf("Enter the data : ");
            scanf("%d",&data);
            n = insert(&root,data);
            if(n == -1){
               printf("%d is duplicate, BST  not allowed dublicate element\n",data);
            }
            else if(n == 1){
               printf("Successfully inserted\n");
            }
            break;
         case 2:
            if(root == NULL)
            {
               printf("Tree is empty\n");
            }
            else{
              printf("Enter the data : ");
              scanf("%d",&data);
              temp = delete(&root,data);
              if(temp == NULL){
                printf("%d is not found\n",data);
              }
              else if(n == 1){
                printf("%d is deleted success\n",data);
              }
            }
            break;
         case 3:
            display(root,0);
            printf("\n");
            break;
         case 4:
            printf("\nPreorder : ");
            pre_order(root);
            printf("\nInorder  : ");
            in_order(root);
            printf("\nPostorder: ");
            post_order(root);
            printf("\n");
            break;
         case 5:
            temp = find_min(root);
            if(temp == NULL){
              printf("Tree is empty\n");
            }
            else{
              printf("Minimum value is %d\n",temp->data);
            }
            break;
         case 6:
            temp = find_max(root);
            if(temp == NULL){
              printf("Tree is empty\n");
            }
            else{
              printf("Maximum value is %d\n",temp->data);
            }
            break;
         case 7:
            printf("\nThank you!!!\n");
            break;
         default:
            printf("Enter valid option\n");
            break;
      }
   }
}

/* Create new Node */
struct node* create_node(int data1){
   /* NewNode creation */
   struct node* newNode;
   newNode = (struct node*)malloc(sizeof(struct node));
   
   /* data of new node */
   newNode->data = data1;
   /* Left Node Reference NULL */
   newNode->left = NULL;
   /* Right Node Reference NULL */
   newNode->right = NULL;
   
   return newNode;
}

/* Insert value */
int insert(struct node **node1, int value) {
    /* The current node is empty */
    if(*node1 == NULL){
        *node1 = create_node(value);
        return 1;
    } 
    else if(value < (*node1)->data){
        insert(&((*node1)->left), value);
    } 
    else if(value > (*node1)->data){
        insert(&((*node1)->right), value);
    }
    else{
      return -1;
    }
}

/* Delete value */
struct node* delete(struct node **node1, int value) {
   /* The current node is empty */
   if(*node1==NULL){
      return NULL;
   }
   else if(value < (*node1)->data){
      delete(&((*node1)->left), value);
   } 
   else if(value > (*node1)->data){
      delete(&((*node1)->right), value);
   }
   else if(value == (*node1)->data){
      /* Case 1 : No child or leaf node */
      struct node *temp;
      if(((*node1)->left)==NULL && ((*node1)->right)==NULL){
         free(*node1);
         *node1 = NULL;
      }/* Case 2 : One child */
      else if(((*node1)->left)==NULL){
         temp = *node1;
         *node1 = (*node1)->right;
         free(temp);
      }
      else if(((*node1)->right)==NULL){
         temp = *node1;
         *node1 = (*node1)->left;
         free(temp);
      }/* Case 3 : two child */
      else{ /* Inorder successor - Min of right subtree */
         temp = find_min((*node1)->right);
         (*node1)->data = temp->data;
         (*node1)->right = delete(&((*node1)->right), temp->data);
      }
   }
   return *node1; 
}

/* Left most element is small in BST */
 struct node* find_min(struct node *node1){
    /* First check the node is empty or not */
    /* First the data value is -1 */
    if(node1 == NULL){
       return node1;
    }
    else if(node1->left == NULL){
       return node1;
   }
    /*Goto left side of node with node data*/
    find_min(node1->left);
}

/* Left most element is small in BST */
struct node* find_max(struct node *node1){
   /* First check the node is empty or not */
   /* First the data value is -1 */
   if(node1 == NULL){
       return node1;  
   }
   else if(node1->right == NULL){
       return node1;
   }
   /*Goto right side of node with node data*/
   find_max(node1->right);
}

/* Get height of root */
int get_height(struct node* node1){
   if(node1==NULL){
      return -1;
   }
   /* Max of left and right of given node*/
   return max(get_height(node1->left),get_height(node1->right))+1;
}

int max(int left,int right){
   return left>right?left:right;
}

/*Display based on traversel */
void pre_order(struct node *node1){
   /* Root  Left  Right */
   if(node1 == NULL ){
      return;
   }
   printf("%d  ",node1->data);
   pre_order(node1->left);
   pre_order(node1->right);
}

void in_order(struct node *node1){
   /* Left Root Right */
   if(node1 == NULL ){
      return;
   }
   in_order(node1->left);
   printf("%d  ",node1->data);
   in_order(node1->right);
}

void post_order(struct node *node1){
   /* Left Right Root */
   if(node1 == NULL ){
      return;
   }
   post_order(node1->left);
   post_order(node1->right);
   printf("%d  ",node1->data);
}

void level_order(struct node *node1){
   /* Using FIFO */
}

/*
Display based on levels
|---->6
5      
|      |---->4
|---->3|
       |---->2
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
