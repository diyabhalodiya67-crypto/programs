    #include<stdio.h>
    #include<math.h>
    #include<ctype.h>

    #define n 20
    int top=-1;
    int value=0;
    int s[20];

    void push(int x)
{

    if (top>= 20-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
    
        top++;
        s[top]=x;
    }
}

   
int pop()
{
    if(top < 0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
      
       return  s[top--];
    }
}
    int main()
    {
        int i,temp,op1,op2;
        char p[]="546+*493/+*";
        while(p[i]!='\0')
        {
            temp=p[i];
            if(isdigit(temp))
            {
                push(temp-'0');
            }
            else
            {
                op2=pop();
                op1=pop();
                switch (temp)
                {
                case '+':
                    value=op2+op1;
                    push(value);
                    break;
                case '-':
                    value=op1-op2;
                    push(value);
                    break;
                case '*':
                    value=op2*op1;
                    push(value);
                    break;
                case '/':
                    value=op1/op2;
                    push(value);
                    break;

                default:
                printf("enter proper choice");
                    break;
                }
               
            }
             i++;
        }
        printf("%d",pop());


    }

