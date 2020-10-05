#include<stdio.h>
#include<math.h>
void main()
{
        float x,y,rad,r,theta;
        printf("Enter the abcissa\n");
        scanf("%f",&x);
        printf("Enter the ordinate\n");
        scanf("%f",&y);
        r=sqrt(pow(x,2)+pow(y,2));
        printf("The distance is %f\n",r);
        if((x>0)&&(y>0))
        {
                rad=atan(y/x);
                theta=(180*rad)/3.14;
        }
        if((x<0)&&(y>0))
        {
                rad=atan(y/-x);
                theta=180-((180*rad)/3.14);
        }
        if((x<0)&&(y<0))
        {
                rad=atan(y/x);
                theta=((180*rad)/3.14)+180;
        }
        if((x>0)&&(y<0))
        {
                rad=atan(-y/x);
                theta=360-((180*rad)/3.14);
        }
        printf("The angle is %f\n",theta);
}
