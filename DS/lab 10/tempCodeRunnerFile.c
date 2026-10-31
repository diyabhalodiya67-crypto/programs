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
    if(front==1)
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
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printf("\n deleted elements is %d",dequeue());
    printf("upddated queue");
    display();
}
