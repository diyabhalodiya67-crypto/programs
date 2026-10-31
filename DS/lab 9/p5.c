// Write a recursive function to calculate the sum of all elements in an array. 
#include<stdio.h>
int sum(int n[] , int x)
{
    if(n==0)
    {
        return 0;
    }
    else{
        return n[x-1] + sum(n,x-1);
    }
}
void main()
{
    int i,x;
    printf("enter x");
    scanf("%d",&x);
    int n[20];
    for(i=0;i<x;i++)
    {
        scanf("%d",&n[i]);
    }
    printf("sum is %d",sum(n,x));
}