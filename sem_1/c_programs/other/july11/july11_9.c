#include<stdio.h>
void main()
{
        int a,b,t,x;
        printf("\n enter the value of a and b");
        scanf("%d%d",&a,&b);
        printf("\n enter the value of x");
        scanf("%d",&x);
        if(x==1)
        {
        a=a+b;
        b=a-b;
        a=a-b;
        printf("\n the values of a and b is %d,%d",a,b);
        }
        if(x==2)
        {
        a=t;
        t=b;
        b=a;
        printf("\n the values of a and b is %d,%d",a,b);
        }
}
