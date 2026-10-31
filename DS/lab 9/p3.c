//Write a recursive function to reverse a given number.
#include<stdio.h>

int reverse(n , rev)
{
   if(n==0)
   {
    return rev ;
   }
   else{
         return reverse(n /10 , rev * 10 + n%10);
   }
}
void main()
{
    int n,result;
    printf("enter n"); 
    scanf("%d",&n);
    result = reverse(n,0); 
    printf("reverse is %d",result);
}