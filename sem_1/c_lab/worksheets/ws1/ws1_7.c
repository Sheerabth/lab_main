#include<stdio.h>
void main()
{
        int feet,inch1,inch2;
        printf("Enter the length in feet\n");
        scanf("%d",&feet);
        printf("Enter the remaining length in inches\n");
        scanf("%d",&inch1);
        inch2=(feet*12)+inch1;
        printf("The total length in inches is %d\n",inch2);
}

