#include<stdio.h>
void main()
{
        int num,i,j;
        printf("Enter the number whose factorial is to be found\n");
        scanf("%d",&num);
        for(j=1;j<=num;j++)
        {
                double n=1;
                for(i=1;i<=j;i++) n*=i;
                printf("The factorial of %d is %f\n",j,n);
        }
}

