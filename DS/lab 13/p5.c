//49. WAP to sort the array elements using Pointer. 
#include<stdio.h>
void main()
{
    int n,i,j,temp;
    printf("enter no of elemnts:");
    scanf("%d",&n);
    int a[n];
    int *ptr;
    ptr=a;

    printf("enter elements of array");
    for(int i=0;i<n;i++)
    {
      scanf("%d",ptr+i);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(*(ptr+i)>*(ptr+j))
            {
                temp=*(ptr+i);
                *(ptr+i) =*(ptr+j);
                *(ptr+j) = temp;

            }
        }
    }
    printf("sorterd array is");
    {

        for(i=0;i<n;i++)
        {
            printf("%d",*(ptr+i));
        }
    }

}