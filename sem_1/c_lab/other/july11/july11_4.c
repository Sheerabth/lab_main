#include<stdio.h>
#include<math.h>
void main()
{
        double a,b,c,d;
        float result;
        printf("\n enter the variables");
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        result=((a+b)/(c-d))+(pow(a+c,0.5)/((a-b))*(c+b)/(a+c));
        printf("\n the result is %0.3f",result);
}

