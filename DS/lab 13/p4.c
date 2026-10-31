//WAP to find the largest element in the array using Pointer. 

#include<stdio.h>
void main()
{
    int n,max=0;
    printf("enter no of elements of array");
    scanf("%d",&n);
    int a[n];
    int *ptr;
    ptr=a;

    printf("enter elements ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
   
    for(int i=0;i<n;i++)
    {
        if(*(ptr+i)> max)
        {
            max=*(ptr+i);
        }
    }
    printf("largest no is %d",max);
}