#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node* traverse(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node)); //creating node pointer
    n->data = data; //allocating data
    n->left = NULL; //left child
    n->right= NULL; //rt child
    return n;
}

//DRL
void preorder (struct node*root){  
    if(root!=NULL){
        printf ("%d ", root->data);
        preorder (root->left);
        preorder (root->right);
    }
}

//LDR
void inorder (struct node*root){  
    if(root!=NULL){

        inorder (root->left);
        printf ("%d ", root->data);
        inorder (root->right);
    }
}

//LRD
void postorder (struct node*root){
    if(root!=NULL){

        postorder (root->left);
        postorder (root->right);
        printf ("%d ", root->data);
    }
}

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

return 0;
}