// WAP to implement Simple Queue, Circular Queue & Priority Queue using singly linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};


struct node* FRONT;
struct node* RARE;

void enqueue(int x){
    struct node* new;
    new = (struct node*) malloc (sizeof(struct node));
    new -> info=x;
    new -> link = NULL;
   
    if(FRONT == NULL){
        FRONT = new;
        RARE=new;
        return;
    }
   RARE->link= new;
   RARE=new;
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
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
}

