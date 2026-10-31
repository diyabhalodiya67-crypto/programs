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

    printf("enter int p\n");
    scanf("%d",p);
    printf("int p is %d\n",*p);

    printf("enter flaot f\n");
    scanf("%d",f);
    printf("float f is %d\n",*f);
    
    printf("enter char c\n");
    scanf("%d",c);
    printf("char c is %d\n",*c);

    free(p);
    free(f);
    free(c);

} 
