
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int data) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int smallest(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int largest(struct node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    struct node* root = NULL;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    if (root == NULL) {
        printf("Tree is empty");
        return 0;
    }

    printf("Smallest element = %d\n", smallest(root));
    printf("Largest element = %d\n", largest(root));

    return 0;
}
