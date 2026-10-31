 //Write a recursive function to find the sum of digits of a given number. 
#include<stdio.h>

int sumofdigit(n)
{
   if(n==0)
   {
    return 0;
   }
   else
   {
     return(n%10) + sumofdigit(n/10);
   }
}
void main()
{
    int n; 
    printf("enter n");
    scanf("%d",&n);
 
    printf("sum of digit is %d",sumofdigit(n));
}