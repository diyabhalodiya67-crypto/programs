
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL;

// Insert node at the front
void insertFront()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &value);

    newnode->data = value;

    if (last == NULL)
    {
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
    }

    printf("Node inserted at front.\n");
}

// Insert node at the end
void insertEnd()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &value);

    newnode->data = value;

    if (last == NULL)
    {
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }

    printf("Node inserted at end.\n");
}

// Delete first node
void deleteFront()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (last == temp)
    {
        last = NULL;
    }
    else
    {
        last->next = temp->next;
    }

    free(temp);
    printf("First node deleted.\n");
}

// Delete last node
void deleteEnd()
{
    struct node *temp, *prev;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last;

    if (last->next == last)
    {
        last = NULL;
    }
    else
    {
        prev = last->next;

        while (prev->next != last)
        {
            prev = prev->next;
        }

        prev->next = last->next;
        last = prev;
    }

    free(temp);
    printf("Last node deleted.\n");
}

// Delete node from specified position
void deletePosition()
{
    struct node *temp, *prev;
    int pos, i;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position to delete (starting from 1): ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        deleteFront();
        return;
    }

    prev = last->next;

    for (i = 1; i < pos - 1 && prev != last; i++)
    {
        prev = prev->next;
    }

    if (prev == last || prev->next == last->next)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = prev->next;
    prev->next = temp->next;

    if (temp == last)
    {
        last = prev;
    }

    free(temp);
    printf("Node at position %d deleted.\n", pos);
}

// Display all nodes
void display()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != last->next);

    printf("(back to first node)\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n--- CIRCULAR LINKED LIST MENU ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete first node\n");
        printf("4. Delete last node\n");
        printf("5. Delete node from specified position\n");
        printf("6. Display all nodes\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                deletePosition();
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}
