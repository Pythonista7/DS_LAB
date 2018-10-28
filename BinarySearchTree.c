// C program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
   
struct binaryTree {
    int data; 
    struct binaryTree *left, *right; 
}; 

typedef struct binaryTree* node;
// A utility function to create a new BST node 
node root = NULL;
node newNode(int element) {
    node temp =  (node)malloc(sizeof(struct binaryTree)); 
    temp->data = element; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(node root) { 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 
   
/* A utility function to insert a new node with given data in BST */
void insert(node new, int key) { 
    /* If the tree is empty, return a new node */
    if (new == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < new->key) 
        new->left  = insert(new->left, key); 
    else if (key > new->key) 
        new->right = insert(new->right, key);    
  
    /* return the (unchanged) node pointer */
} 
   
// Driver Program to test above functions 
int main() { 
   int choice;
    
   printf("1. Insert nodes into tree\n2. Display tree\n3. Exit\n");
   do{
      printf("\nEnter your choice - ");
      scanf("%d", &choice);
      switch(choice){
         case 1:{
            printf("Enter the data for root node - ");
            scanf("%d", &data);
            insert(root, data);
         } break;
         case 2: inorder(root); break;
         case 3: return 0;
      }
   }while(choice != 0);
   return 0; 
} 
