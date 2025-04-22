#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node* traverse(int data){
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = data;
    Node->left = NULL;
    Node->right= NULL;
    return Node;
}

void preorder (struct node*root){
    if(root!=NULL){
        printf ("%d ", root->data);
        preorder (root->left);
        preorder (root->right);
    }
}

void inorder (struct node*root){
    if(root!=NULL){

        inorder (root->left);
        printf ("%d ", root->data);
        inorder (root->right);
    }
}

void postorder (struct node*root){
    if(root!=NULL){

        postorder (root->left);
        postorder (root->right);
        printf ("%d ", root->data);
    }
}
 
int depth(struct node*root){
    if (root==NULL)
    return 0;

    else {
        int leftdepth= depth(root->left);
        int rightdepth= depth(root->right);
        return (leftdepth >rightdepth ? leftdepth : rightdepth) + 1;
    }} 

/*

  5           
 / \
 2  8
/ \     
1  4

*/

int main(){
struct node*root= traverse(5);
root->left= traverse(2);
root->right= traverse(8);
root->left->left= traverse(1);
root->left->right= traverse(4);

printf("Preorder: ");
preorder (root);
printf ("\n"); 

printf("Inorder: ");
inorder (root);
printf ("\n");

printf ("Postorder: ");
postorder (root);
printf ("\n");

printf("depth of the tree is: %d", depth(root));

return 0;
}