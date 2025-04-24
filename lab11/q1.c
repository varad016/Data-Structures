#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *nnode = (struct node *) malloc(sizeof(struct node));
    nnode->data = data;
    nnode->left = NULL;
    nnode->right = NULL;
    return nnode;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct node *buildTree(int inorder[], int preorder[], int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd)
        return NULL;
    int curr = preorder[*preIndex];
    (*preIndex)++;
    struct node *tNode = createNode(curr);
    if (inStart == inEnd)
        return tNode;
    int inIndex = search(inorder, inStart, inEnd, curr);
    tNode->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    tNode->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);
    return tNode;
}

void printInorder(struct node *root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

void printPreorder(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int choice;
    struct node *root = NULL;

    while (1) {
        printf("Enter your choice:-\n 1. Build tree using inorder and preorder\n 9. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int n;
            printf("Enter number of nodes: ");
            scanf("%d", &n);

            int *inorder = (int *)malloc(n * sizeof(int));
            int *preorder = (int *)malloc(n * sizeof(int));

            printf("Enter inorder traversal: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &inorder[i]);
            }
            printf("Enter preorder traversal: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &preorder[i]);
            }

            int preIndex = 0;
            root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

            printf("Inorder: ");
            printInorder(root);
            printf("\nPreorder: ");
            printPreorder(root);
            printf("\n");

            free(inorder);
            free(preorder);
        } else if (choice == 9) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}