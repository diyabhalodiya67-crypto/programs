#include<stdio.h>
#define n 10

int CQ[n];
int F=-1;
int R=-1;
void enqueue(int y)
{
    if((R+1)%n==F)
    {
        printf("queue is overflow");
        return;
    }
    R=(R+1)%n;
    CQ[R]=y;
    if(F==-1)
    {
        F=0;
    }
}
int dequeue()
{
    if(F==-1)
    {

        printf("underflow \n");
        return -1;
    }
    else{
        int y=CQ[F];
        if(F=R)
        {
            F=R=-1;
        }
        else{
            F=(F+1)%n;
            return y;
        }
    }
}
void display()
{
     if(F==-1)
    {
        printf("overflow");
        return;
    }
    for(int i=F;i!=R;i=(i+1)%n)
    {
       printf("%d\t",CQ[i]);
    }
    printf("%d\t",CQ[R]);
}
void main()
{
int choice, x;

    while(1)
    {
        printf("1. enqueue \n 2. dequeue \n 3.Display");

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
