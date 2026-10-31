#include<stdio.h>
#define n 10

int front=-1;
int rare=-1;
int Q[n];

void enqueue(int x)
{
   if(rare== n-1){

    printf("queue is overflow");
    return;
   }
   rare++;
   Q[rare] = x;
   if(front==-1)
   {
    front=0;
   }
}
int dequeue()
{
    if(front==-1)
    {
        printf("queue is underflow");
        return -1;

    }
    else{
        int x=Q[front];
        if(front=rare)
        {
            front=rare=-1;
            return -1;
        }
        else{
            front++;
            return x;
        }
    }
}
void display()
{
    if(front==-1)
    {
        printf("overflow");
        return;
    }
    for(int i=front;i<=rare;i++)
    {
       printf("%d\t",Q[i]);
    }
}
void main()
{
int choice, x;

    while(1)
    {
        printf("1. enqueue \n 2. dequeue \n 3. Display");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
