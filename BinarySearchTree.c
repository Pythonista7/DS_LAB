// C program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
   
struct binaryTree {
    int data; 
    struct binaryTree *left, *right; 
}; 

typedef struct binaryTree* node;
// A utility function to create a new BST node 
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
node insert(node new, int key) { 
    /* If the tree is empty, return a new node */
    if (new == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < new->key) 
        new->left  = insert(new->left, key); 
    else if (key > new->key) 
        new->right = insert(new->right, key);    
  
    /* return the (unchanged) node pointer */
    return new; 
} 
   
// Driver Program to test above functions 
int main() { 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    node root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    // print inoder traversal of the BST 
    inorder(root); 
   
    return 0; 
} 