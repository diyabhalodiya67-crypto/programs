
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int sameTree(struct Node *a, struct Node *b) {
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    return (a->data == b->data &&
            sameTree(a->left, b->left) &&
            sameTree(a->right, b->right));
}
