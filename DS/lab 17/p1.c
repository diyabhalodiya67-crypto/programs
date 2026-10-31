//WAP to swap Kth node from beginning with Kth node from end in a singly linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
int K;
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
int count_nodes()
{
    int count=0;
    struct node *temp;
    temp=FIRST;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;

}
int swap_K(int K)
{
    int n=count_nodes();
    if(K>n)
    {
        printf("K is greater ");
        return 0;
    }
    else if(2*K-1==n)
    {
        printf("Kth node from end and same are same:");
        return 0;
    }
    struct node *first=FIRST,*first_prev=NULL;
    for(int i=1;i<K;i++)
    {
        first_prev=first;
        first=first->link;
    }

    struct node *second=FIRST,*second_prev=NULL;
    for(int i=1;i<n-K+1;i++)
    {
        second_prev=second;
        second=second->link;
    }

    int temp=first->info;
    first->info = second->info;
    second->info=temp;
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
void main()
{
int x,n1,K,i=0;

    printf("enter the size of linked list");
    scanf("%d",&n1);

    while(i<n1)
        {
            printf("enter elememts to insert :");
            scanf("%d",&x);
            insert(x);
            i++;
        }
    display();
    printf("enter the value of K");
    scanf("%d",&K);
    swap_K(K);

    display();
}