#include<stdio.h>
#define n 5

int F =-1;
int R =-1;
int Dequeue[n];

void insert_RARE(int y)
{
    if(R==n-1)
    {
        printf("queue is overflow");
        return;
    }
}
R++;
Dequeue[R]=y;
if(F==-1)
{
    F=0;
}
int delete_FRONT()
{
    if(F==-1)
    {
        printf("queue is overflow");
        return -1;
    }
    else
    {
        int y=Dequeue[F];
        int(F==R)
        {
            F=R=-1;
        }
        else{
            F++;
        }
        return y;
    }
}
void insert_FRONT(int y)
{
    if(F==0)
    {
        printf("double ended queue ");
        return;
    }
    else{

        if(F==-1)
        {
            F=R=0;
        }
        else{
            F--;
        }
        Dequeue[F]=y;
    }
}
int delete_RARE()
{
    if(R==-1)
    {
        printf("double ended queue overflow");
        return -1;
    }
    else{
        int y = Dequeue[R];
        if(F==R)
        {
        F=R=-1;
        }
        else{

            R--;
        }
        return y;
    }
}
void display()
{
    if(F==-1)
    {
        printf("double ended queue underflow");
        return;
    }
    for(int i=F;i<=R;i++)
    {
        printf("%d",Dequeue[i]);
    }
}
void main()
{
int choice, x;

    while(1)
    {
        printf("1. insert_RARE \n 2. delete_FRONT \n 3.insert_FRONT \n 4.delete_RARE \n 5.delete_RARE \n 6.display");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                insert_RARE(x);
                break;
            case 2:
                delete_FRONT();
                break;
            case 3:
                printf("Enter the element to insert_FRONT: ");
                scanf("%d", &x);
                insert_FRONT(x);
                break;
            case 4:
                delete_RARE();
                break;
            case 5:
                delete_RARE();
                break;
            case 6:
               display();
               break;
            default:
             printf("enter poper choice");
        }
    }
}
