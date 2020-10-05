#include<stdio.h>
void main()
{
        int no,u,t,h,th;
        printf("Enter the four digit number\n");
        scanf("%d",&no);
        th=no/1000;
        h=(no%1000)/100;
        t=(no%100)/10;
        u=no%10;
        if((u==0||u==1)&&(t=0||t==1)&&(h==0||h==1)&&(th==0||th==1))
        {
                printf("It is a binary\n");
        }
        else
        {
                printf("It is not a binary\n");
        }
}
