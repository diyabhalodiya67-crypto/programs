#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *FIRST = NULL;

void insert(int x)
{
    struct node *new;
    new = (struct node*) malloc (sizeof(struct node));
    new -> info=x;
    new -> link = NULL;
   
    if(FIRST == NULL){
        FIRST = new;
        return;
    }
    struct node *save;
    save = FIRST;
    while(save -> link != NULL ){
        save = save -> link;
    }
    save->link = new;
}
void display()
{
    if(FIRST == NULL){
        printf("Linked list is empty");
        return;
    }
    struct node *save;
    save=FIRST;
    while(save != NULL){
        printf("%d \t",save-> info);
        save = save ->link;
    }
}
void delete()
{
 struct node *save;
 
 save=FIRST;
 
 while (save->link!= NULL && save!=NULL)
 {
    if(save->info == save->link->info)
    {
       save->link=save->link->link;
    }
    else{
        save=save->link;
    }
 }
}
void main()
{
    insert(1);
    insert(1);
    insert(6);
    insert(13);
    insert(13);
    display();
    delete();
    display();
}