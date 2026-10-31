// WAP to allocate and de-allocate memory for int, char and float variable at runtime. 
#include<stdio.h>
void main()
{
    int *p;
    float *f;
    char *c;

    p=(int*)malloc(sizeof(int));
    f=(float*)malloc(sizeof(float));
    c=(char*)malloc(sizeof(char));

    printf("enter int p");
    scanf("%d",p);
    printf("int p is %d",*p);

    printf("enter flaot f");
    scanf("%d",f);
    printf("float f is %d",*f);
    
    printf("enter char c");
    scanf("%d",c);
    printf("char c is %d",*c);

    free(p);
    free(f);
    free(c);

} 
