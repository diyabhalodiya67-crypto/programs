// WAP to calculate the sum of n numbers using Pointer.
#include<stdio.h>
void main()
{
   
    int n, sum=0;

    printf("enter no of elements:");
    scanf("%d",&n);
    int a[n];
    int *ptr;
    ptr=a;

    printf("enter elemets of array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
    printf("sum of array is");
    for(int i=0;i<n;i++)
    {
          sum=sum+*(ptr+i);
    }
    printf("sum is %d",sum);
}