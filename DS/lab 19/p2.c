
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create circular linked list
void create()
{
    struct node *newnode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;

            while (temp->next != head)
                temp = temp->next;

            temp->next = newnode;
            newnode->next = head;
        }
    }
}

// Split circular linked list into two halves
void split()
{
    struct node *slow, *fast;
    struct node *head1, *head2;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head)
    {
        printf("First half: %d\n", head->data);
        printf("Second half: Empty\n");
        return;
    }

    slow = head;
    fast = head;

    while (fast->next != head &&
           fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    head1 = head;
    head2 = slow->next;

    slow->next = head1;
    fast->next = head2;

    printf("First half: ");
    struct node *temp = head1;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head1);

    printf("\nSecond half: ");
    temp = head2;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head2);

    printf("\n");
}

int main()
{
    create();
    split();

    return 0;
}
