// Priority Queue 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    int priority;
    struct node* link;
};
struct node* FRONT;
struct node* RARE;
void enqueue(int data, int prio)
{
    struct node *new;
    new = (struct node*) malloc (sizeof(struct node));
    new->info=data;
    new->priority = prio;

    if(FRONT==NULL)
    {
        new->link=new;
        FRONT=RARE=new;
        return;
    }
    if(new->priority <=FRONT->priority)
    {
        new->link=FRONT;
        RARE->link=new;
        FRONT=new;
        return;
    }
    struct node* save;
    while(save!=RARE && new->priority >= save->link->priority)
    {
        save = save->info;
    }
    new->link = save->link;
    save->link=new;
    if(save==RARE)
    {
        RARE=new;
    }

}
void dequeue()
{
    if(FRONT==NULL)
    {
        printf("underflow");
        return;
    }
    struct node* pred;
    pred=FRONT;
    FRONT=FRONT->link;
    free(pred);
}
void display(){
    if(FRONT == NULL){
        printf("Linked list is empty");
        return;
    }
    struct node *save;
    save=FRONT;
    while(save != NULL){
        printf("%d \t",save-> info);
        save = save ->link;
    }
}
void main()
{
    enqueue(10,1);
    enqueue(20,3);
    enqueue(30,2);
    display();

}
