#include<stdio.h>
#include<math.h>
void main()
{
        float a,b,c,A,B,C,area;
        printf("\n enter the value of A");
        scanf("%f",&A);
        printf("\n enter the value of a,b");
        scanf("%f%f",&a,&b);
        B=asin(fabs(b*sin(A)/a))*180/3.14;
        C=fabs(180-(A+B))*180/3.14;;
        c=(fabs(b*sin(C)/sin(B)));
        area=fabs(0.5*a*b*sin(C));
        printf("\n angle B,angle C,side c ,area is %f,%f,%f,%f",B,C,c,area$
}

