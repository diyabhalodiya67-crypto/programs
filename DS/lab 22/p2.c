
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[20];
    struct Node *left, *right;
};

struct Node* createNode(char name[], char phone[]) {
    struct Node *newNode = malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;

    return newNode;
}

// Add new entry
struct Node* insert(struct Node *root, char name[], char phone[]) {
    if (root == NULL)
        return createNode(name, phone);

    int cmp = strcmp(name, root->name);

    if (cmp < 0)
        root->left = insert(root->left, name, phone);
    else if (cmp > 0)
        root->right = insert(root->right, name, phone);
    else
        strcpy(root->phone, phone);

    return root;
}

// Search phone number by name
struct Node* search(struct Node *root, char name[]) {
    if (root == NULL || strcmp(name, root->name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return search(root->left, name);

    return search(root->right, name);
}

// Find smallest node
struct Node* minNode(struct Node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// Delete an entry
struct Node* deleteNode(struct Node *root, char name[]) {
    if (root == NULL)
        return NULL;

    int cmp = strcmp(name, root->name);

    if (cmp < 0)
        root->left = deleteNode(root->left, name);
    else if (cmp > 0)
        root->right = deleteNode(root->right, name);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minNode(root->right);

        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);

        root->right = deleteNode(root->right, temp->name);
    }

    return root;
}

// Ascending order
void ascending(struct Node *root) {
    if (root != NULL) {
        ascending(root->left);
        printf("%s : %s\n", root->name, root->phone);
        ascending(root->right);
    }
}

// Descending order
void descending(struct Node *root) {
    if (root != NULL) {
        descending(root->right);
        printf("%s : %s\n", root->name, root->phone);
        descending(root->left);
    }
}

int main() {
    struct Node *root = NULL;
    char name[50], phone[20];
    int choice;

    do {
        printf("\n--- PHONE BOOK ---\n");
        printf("1. Add Entry\n");
        printf("2. Remove Entry\n");
        printf("3. Search Phone Number\n");
        printf("4. List Ascending Order\n");
        printf("5. List Descending Order\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf(" %49[^\n]", name);
            printf("Enter phone number: ");
            scanf(" %19s", phone);
            root = insert(root, name, phone);
            printf("Entry added successfully!\n");
            break;

        case 2:
            printf("Enter name to remove: ");
            scanf(" %49[^\n]", name);

            if (search(root, name) != NULL) {
                root = deleteNode(root, name);
                printf("Entry removed successfully!\n");
            } else {
                printf("Entry not found!\n");
            }
            break;

        case 3:
            printf("Enter name to search: ");
            scanf(" %49[^\n]", name);

            struct Node *result = search(root, name);

            if (result != NULL)
                printf("Phone Number: %s\n", result->phone);
            else
                printf("Entry not found!\n");
            break;

        case 4:
            printf("\nEntries in Ascending Order:\n");
            ascending(root);
            break;

        case 5:
            printf("\nEntries in Descending Order:\n");
            descending(root);
            break;

        case 6:
            printf("Exiting Phone Book.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
