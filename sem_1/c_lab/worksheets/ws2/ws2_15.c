#include<stdio.h>
void main()
{
        int x1,x2,y1,y2;
        float xm,ym,m,c;
        printf("Enter the first point's abscissa\n");
        scanf("%d",&x1);
        printf("Enter the first point's ordinate\n");
        scanf("%d",&y1);
        printf("Enter the second point's abscissa\n");
        scanf("%d",&x2);
        printf("Enter the second point's ordinate\n");
        scanf("%d",&y2);
        xm=(x1+x2)/2;
        ym=(y1+y2)/2;
        if(x1==x2&&y1==y2) printf("Both are same points\n");
        else if(y1==y2) printf("Equation of perpendicular bisector is x=%f$
        else
        {
                m=(x1-x2)/(y2-y1);
                c=ym-(m*xm);
                printf("Equation of perpendicular bisector is y=%fx+%f\n",$
        }
}
