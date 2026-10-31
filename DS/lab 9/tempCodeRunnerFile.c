//Write a recursive function to reverse a given number.
#include<stdio.h>

int reverse(n , rev)
{
   if(n==0)
   {
    return 0;
   }
   else{
         return (n%10) + reverse(n*10+n);
   }
}
void main()
{
    int n;
    printf("enter n");
    scanf("%d",&n);

    printf("reverse is %d",reverse(n));
}