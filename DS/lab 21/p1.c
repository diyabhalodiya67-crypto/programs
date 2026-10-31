#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*lptr;
    struct node *rptr;
    int info;

};
//insert node
struct  node* insert(struct node* root,int data)
{
    if(root==NULL)
    {
        struct node* new;
        new =(struct node*)malloc(sizeof(struct node));
        new->info=data;
        new->lptr=NULL;
        new->rptr=NULL;
        return new;
    }
    if(data < root->info)
    {
        root->lptr=insert(root->lptr,data);

    }
    else if(data > root->info)
    {
        root->rptr=insert(root->rptr,data);
    }
    return root;
}

//search node
struct node* search(struct node* root,int data)
{
    if(root==NULL || root->info==data)
    {
        return root;
    }
    if(data<root->info)
    {
        return search(root->lptr,data);
    }
    else
    {
        return search(root->rptr,data);
    }
}

//find min 
struct node* findmin(struct node* root)
{
    while(root->lptr !=NULL)
    {
        root=root->lptr;
    }
    return root;
}

//delete node
struct node* delete(struct node *root,int data)
{
    if(root=NULL)
    {
        return root;
    }
    if(data < root->info)
    {
        root->lptr=delete(root->lptr,data);
    }
    else if(data > root->info)
    {
        root->rptr=delete(root->rptr,data);
    }
    else
    {
       if(root->lptr==NULL)
       {
        struct node* temp=root->rptr;
        free(root);
        return temp;
       } 
       if(root->rptr==NULL)
       {
        struct node* temp=root->lptr;
        free(root);
        return temp;
       }
       struct node* temp=findmin(root->rptr);
         root->info=temp->info;
         root->rptr=delete(root->rptr,temp->info);
    }
    return root;
}
//preorder

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d",root->info);
        preorder(root->lptr);
        preorder(root->rptr);
    }
}

//post order

void postorder(struct node* root)
{
    if(root!=NULL)
    {
        
        postorder(root->lptr);
        postorder(root->rptr);
        printf("%d",root->info);

    }
}

//inorder 

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->lptr);
        printf("%d",root->info);
        inorder(root->rptr);
    }
}
void main()
{
    int choice ,value;
    struct node* root=NULL;

    do
    {
        printf("\n 1. insertt");
        printf(" \n2. delete");
        printf(" \n3. search");
        printf(" \n4. preorder");
        printf(" \n5. postorder");
        printf(" \n6. inorder");
        printf(" \n7. exit");

        printf("\n enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("enter a value");
            scanf("%d",&value);
            root=insert(root,value);
            printf("node inserted succesfully");
            break;

            case 2:
            printf("enter value to delete");
            scanf("")
        }

        
    }
}