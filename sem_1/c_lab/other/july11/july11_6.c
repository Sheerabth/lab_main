#include<stdio.h>
#include<math.h>
void main()
{
        float a1,m1,m2,b1,c1,a2,b2,c2,x,y,theta;
        printf("\n enter values of a1,b1,c1");
        scanf("%f%f%f",&a1,&b1,&c1);
        printf("\n enter the values of a2,b2,c2");
        scanf("%f%f%f",&a2,&b2,&c2);
        x=(b1*c2-b2*c1)/(a1*b2-a2*b1);
        y=(c1*a2-c2*a1)/(a1*b2-a2*b1);
        printf("\n the point of intersection is %f,%f",x,y);
        m1=-(a1/b1);
        m2=-(a2/b2);
        theta=atan(fabs(m1-m2)/(1+m1*m2))*180/3.14;
        printf("\n the angle is %f",theta);
}
