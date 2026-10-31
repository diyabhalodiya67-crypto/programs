// WAP to get and print the array elements using Pointer. 

#include<stdio.h>
#include<stdlib.h>
void main()
{
    int a[100] , n , *p;
    p=a;
    printf("enter no of elements:");
    scanf("%d",&n);

    printf("Enter elements:\n");

    for(int i=0;i<n;i++)

    {
        scanf("%d",p+i);
    }

    printf("elements of array are");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",*(p+i));
    }
    
}