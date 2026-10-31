#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};

struct node *FIRST = NULL;

//insert node at first 
void insert(int x){
    struct node *new;
    new = (struct node*) malloc (sizeof (struct node) );
    new -> info=x;
    new -> link = FIRST;
    FIRST = new; 
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
    printf("Press:0 for Exit Press:1 to insert node at first \n Press:2 to insert node at last \n Press:3 for Display \n");
    scanf("%d", &choice);
        switch (choice)
    {
        
        case 1:
         printf("Enter elements to insert at first:\n");
         scanf("%d",&x);
        insert(x);
        break;

        case 2:

        // printf("Enter elements to insert at last:\n");
        //  scanf("%d",&x);
        // insend(x);
        // break;

        case 3:
        display();
        break;

        default:
        printf("Enter valid choice:\n");
        break;
    }
    }
   
    
}