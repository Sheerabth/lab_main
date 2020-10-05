#include<stdio.h>
#include<math.h>
void main()
{
        int a,b,c,d;
        float x1,x2,real,img;
        printf("Enter the value of a\n");
        scanf("%d",&a);
        printf("Enter the value of b\n");
        scanf("%d",&b);
        printf("Enter the value of c\n");
        scanf("%d",&c);
        d=((b*b)-(4*a*c));
        if(d==0)
        {
                printf("The roots are real and equal\n");
                x1=x2=(-b/(2*a));
                printf("The root is %f\n",x1);
        }
        else if(d>0)
        {
                printf("The roots are real and unique\n");
                x1=(-b+sqrt(d))/(2*a);
                x2=(-b-sqrt(d))/(2*a);
                printf("The roots are %f and %f\n",x1,x2);
        }
        else
        {
                printf("The roots are imaginary\n");
                real=(-b/(2*a));
                x1=sqrt(-d);
                x2=-sqrt(-d);
                printf("The first root is %f+%fi\n",real,x1);
                printf("The second root is %f+%fi\n",real,x2);
        }
}

