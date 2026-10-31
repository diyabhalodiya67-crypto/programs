#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};

struct node *TOP = NULL;

//insert node at first 
void push(int x){
    struct node *new;
    new = (struct node*) malloc (sizeof (struct node) );
    new -> info=x;
    new -> link = TOP;
    TOP = new; 
}

void pop()
{
    if(TOP==NULL)
    {
        printf("underflow");
        return;
    }
    struct node *pred;
    pred=TOP;
    TOP=TOP->link;
    free(pred);
}
int peek()
{
    if(TOP=NULL)
    {
        printf("emplty");
        return 0;
    }
    else{
        return TOP->info;
    }
}
void display(){
    if(TOP == NULL){
        printf("Linked list is empty");
        return;
    }
    struct node *save;
    save=TOP;
    while(save != NULL){
        printf("%d \t",save-> info);
        save = save ->link;
    }
}
void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
    pop();
    display();
}


