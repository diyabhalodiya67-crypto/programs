//WAP to check whether 2 singly linked lists are same or not. 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};
struct node *FIRST = NULL;
struct node *FIRST1 = NULL;
int flag=1;


void insert1(int x){
    struct node* new;
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
void insert2(int x){
    struct node* new;
    new = (struct node*) malloc (sizeof(struct node));
    new -> info=x;
    new -> link = NULL;
   
    if(FIRST1 == NULL){
        FIRST1 = new;
        return;
    }
    struct node *save;
    save = FIRST1;
    while(save -> link != NULL ){
        save = save -> link;
    }
    save->link = new;
}
int check()
{

    while(FIRST->link!=NULL && FIRST1->link!=NULL)
    if(FIRST->info!=FIRST1->info)
    {
     flag=0;
    }
    else{
        FIRST=FIRST->link;
        FIRST1=FIRST1->link;
    }


}
void display1(){
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
void display2(){
    if(FIRST1 == NULL){
        printf("Linked list is empty");
        return;
    }
    struct node *save;
    save=FIRST1;
    while(save != NULL){
        printf("%d \t",save-> info);
        save = save ->link;
    }
}
void main()
{
   
    printf("enter 1st linkedlist");
    insert1(1);
    insert1(2);
    insert1(3);
    display1();

    printf("enter 2nd linkedlist\n");
    insert2(1);
    insert2(2);
    insert2(3);
    display2();

    check();
    if(flag==0)
    {
        printf("not same");
    }
    else{
        printf("same");
    }
    

}