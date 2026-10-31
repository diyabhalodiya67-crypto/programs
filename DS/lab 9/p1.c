//Write a recursive function to generate the nth Fibonacci number.

#include<stdio.h>
 int Fibonacci(int n)
 {
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else{
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
 }
 void main()
 {
   int n;
    printf("enter a n");
    scanf("%d",&n);

    printf("fibbonaci %d",Fibonacci(n));

    return 0;
 }

