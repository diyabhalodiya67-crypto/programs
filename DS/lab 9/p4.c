//Write a recursive function to find the largest element in a given array

#include<stdio.h>
int large(int n[], int s)
{
    if(s==1)
    {
        return n[0];
    }
    int max =large(n,s-1);

    if (n[s-1] > max)
    {
        return n[s-1];
    }
    else{
        return max;
    }
}
void main()
{
    int i,s;

    printf("enter s");
    scanf("%d",&s);

    printf("enter the elements:");
    int n[s];

    for(i=0;i<s;i++)
    {
        scanf("%d",&n[i]);
    }
    printf("max is %d",large(n,s));

}