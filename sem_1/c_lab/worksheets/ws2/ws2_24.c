#include<stdio.h>
void main()
{
        int num,sum=0;
        printf("Enter the number\n");
        scanf("%d",&num);
        while(num>0)
        {
                sum+=num%10;
                num/=10;
        }
        printf("Sum of digits of given number is %d\n",sum);
}
