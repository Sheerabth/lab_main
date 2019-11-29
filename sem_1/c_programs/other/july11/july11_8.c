#include<stdio.h>
void main()
{
        float area,height1,height2,base,tension,m1,m2,g;
        g=9.8;
        printf("\n enter the value of base");
        scanf("%f",&base);
        printf("\n enter the value of height1 and height 2");
        scanf("%f%f",&height1,&height2);
        area=(base*(height1+height2))/2;
        printf("\n enter the values of m1 and m2");
        scanf("%f%f",&m1,&m2);
        tension=((2*m1*m2)/(m1+m2))*g;
        printf("\n area is %f",area);
        printf("\n tension is %f",tension);
}
