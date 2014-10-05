#include<stdio.h>
#include<stdlib.h>
 
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{
    struct node* node = (struct node*)
                           malloc(sizeof(struct node));
 
    node->data = data;
    node->left = NULL;
    node->right = NULL;  
    return(node);
}
 
/*  This function traverses tree in post order to 
    to delete each and every node of the tree */
void deleteTree(struct node* node) 
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
   
    /* then delete the node */
    printf("\n Deleting node: %d", node->data);
    free(node);
} 
 
 
/* Driver program to test deleteTree function*/   
int main()
{
    struct node *root = newNode(1); 
    root->left            = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right   = newNode(5); 
   
    deleteTree(root);  
    root = NULL;
 
    printf("\n Tree deleted ");
   
    getchar();
    return 0;
}
The above deleteTree() function deletes the tree, but doesn’t change root to NULL which may cause problems if the user of deleteTree() doesn’t change root to NULL and tires to access values using root pointer. We can modify the deleteTree() function to take reference to the root node so that this problem doesn’t occur. See the following code.

#include<stdio.h>
#include<stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                           malloc(sizeof(struct node));
 
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
/*  This function is same as deleteTree() in the previous program */
void _deleteTree(struct node* node)
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);
 
    /* then delete the node */
    printf("\n Deleting node: %d", node->data);
    free(node);
}
 
/* Deletes a tree and sets the root as NULL */
void deleteTree(struct node** node_ref)
{
  _deleteTree(*node_ref);
  *node_ref = NULL;
}
 
/* Driver program to test deleteTree function*/
int main()
{
    struct node *root = newNode(1);
    root->left            = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right   = newNode(5);
 
    // Note that we pass the address of root here
    deleteTree(&root);
    printf("\n Tree deleted ");
 
    getchar();
    return 0;
}
