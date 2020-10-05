#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
        int a,x;
        printf("\n enter scissor or rock or paper");
        scanf("%d",&a);
        x=rand()%3;
        printf("\n the computer's number is %d",x);
        if(a==0&&x==0||a==1&&x==1||a==2&&x==2)
        {
                printf("\n draw");
        }
        else if(a==0&&x==2||a==1&&x==0||a==2&&x==1)
        {
                printf("\n user wins");
        }
        else if(a==2&&x==0||a==0&&x==1||a==1&&x==2)
        {
                printf("\n computer wins");
        }
}

