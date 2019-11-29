#include<stdio.h>
void main()
{
        int a,b,m,c,d,n;
        float x1,x2;
        printf("Enter the value of a,b and m\n");
        scanf("%d%d%d",&a,&b,&m);
        printf("Enter the value of c,d and n\n");
        scanf("%d%d%d",&c,&d,&n);
        if((a*d-c*b)==0)
        {
        printf("No solution\n");
        }
        else
        {
        x1=(m*d-b*n)/(a*d-c*b);
        x2=(n*a-m*c)/(a*d-c*b);
        printf("The solution for the two linear equations are %f and %f",x$
        }
}
