#include<stdio.h>
#include<string.h>
#define n 20
int rank =0;
int top=-1; 
int s[n];
n
void push(char x)
{
    s[++top]=x;
}
int pop()
{
    return s[top--];
}

int G(char c)
{
    if(c=='+' || c=='-')
    {
        return 2;
    }
    else if(c=='*' || c=='/')
    {
        return 4;
    }
    else if(c=='^')
    {
        return 5;
    }
    else if(c=='(')
    {
        return 0;
    }
    else{
        return 0;
    }
}

int F(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if(c=='*' || c=='/')
    {
        return 3;
    }
    else if(c=='^')
    {
        return 6;
    }
    else if(c=='(')
    {
        return 9;
    }
    else{
        return 0;
    }
}

int r(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' ||  c=='^')
    {
        return -1;
    }
    else{
        return 1;
    }
}
void revpol(char infix[])
{
    char polish[100] , temp,next;
    int j=0,i=0;
    printf("%s",next);
    push('(');
    int rank=0;
    while(infix[i]!='\0')
    {
        char next=infix[i];
        if(top<0)
        {
            printf("invalid");
            return;
            
        }
        while(G(s[top])> F(next))
        {
             temp = pop();
             polish[j++] =  temp;
             rank=rank+r(temp);
             if(rank<1)
             {
                printf("invalid");
                return;
             }
        }
        if(G(s[top])!=F(next))
        {
            push(next);
        }
        else{
            char x=pop();
        }
        i++;
    } 
    polish[j]='\0';
    if(top!=-1 || rank!=1){
        printf("invalid");
        return;
    }
    else{
        printf("%s",polish);
    }
}
void main()
{
    char infix[100];
    printf("enter a infix expression:");
    scanf("%s",infix);
    printf("%s",infix);
    strcat(infix,")");
    revpol(infix);
    
}
