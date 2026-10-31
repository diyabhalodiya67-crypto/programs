//WAP to copy a linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};

struct node *save;
struct node *FIRST = NULL;

//insert node at first 

void insert(int x){
    struct node *new;
    new = (struct node*) malloc (sizeof (struct node) );
    new -> info=x;
    new -> link = FIRST;
    FIRST = new; 
}
//copy ll
struct node *copy_ll()
{
    struct node *save1;
    struct node *new;
    struct node *FIRST1;
    

    if(FIRST==NULL)
    {
      printf("emptyy");
    }

    new = (struct node*) malloc (sizeof (struct node) );
    new->info = FIRST->info;
    
    FIRST1=new;

    save=FIRST;

    while(save->link !=NULL)
    {
     save1=new;
     save1=save->link;

     struct node * new;
     new -> info =save->info;

     save1 -> link=new;
     return FIRST1;
    }
}
//display function
void display(){
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


void main()
{
    int choice;
    int pos,x;
    int p;
    
    while(1)
    {
    printf("\nEnter your choice for linked operation:\n");
    printf(":1 to insert node at first \n Press:2 for copy  \n Press:3 for Display \n");
    scanf("%d", &choice);
        switch (choice)
    {
        
        case 1:
         printf("Enter elements to insert at first:\n");
         scanf("%d",&x);
        insert(x);
        break;

        case 2:
        copy_ll();
        break;

        case 3:
        display();
        break;

        default:
        printf("Enter valid choice:\n");
        break;
    }
    }
} 
