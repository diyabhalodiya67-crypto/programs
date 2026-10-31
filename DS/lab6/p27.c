#include<stdio.h>
struct intervals{
    int start;
    int end;
}; 

struct intervals stack[3];
int top=-1;

    void push(struct intervals x)
    {
        stack[++top]=x;
    }
    struct intervals pop()
    {
        stack[top--];
    }

void main()
{
     struct intervals a[3],temp;
     int i,j;
     printf("enter a numbers");
     for(i=0;i<3;i++)
     {
        scanf("%d %d",&a[i].start , &a[i].end);
     }
    //  for(i=0;i<3;i++)
    //  {
    //     printf("start:%d\n end:%d\n",a[i].start , a[i].end);
    //  }

    //  for(i=0;i<3-1;i++)
    //  {
    //     for(j=i+1;j<3;j++)
    //     {
    //        if(a[i].start > a[j].start)
    //        {
    //         temp=a[i];
    //         a[i]=a[j];
    //         a[j]=temp;
    //        }
    //     }

    //  }
     //sorted array
     for(i=0;i<3;i++)
     {
         printf("start:%d\n end:%d\n",a[i].start , a[i].end);
     }
     //merge
     push(a[0]);
     for(i=1;i<3;i++)
     {
        temp=pop();
        if(temp.end>a[i].start)
        {
            if(a[i].end > temp.end)
            {
                temp.end=a[i].end;
                push(temp);
            }
            else{
                push(temp);
                
            }
        }
        else{
            push(temp);
            push(a[i]);
        }
     }
     for(i=0;i<3;i++)
     {
       printf("start:%d\n end:%d\n",stack[i].start , stack[i].end);
     }
     

}
