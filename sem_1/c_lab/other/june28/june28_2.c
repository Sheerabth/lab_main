#include<stdio.h>
void main()
{
        int a,b,c,sum,dif;
        printf("Enter the first number\n");
        scanf("%d",&a);
        printf("Enter the second number\n");
        scanf("%d",&b);
        sum=a+b;
        dif=a-b;
        printf("The sum in decimal is %d\n",sum);
        printf("The difference in decimal is %d\n",dif);
        printf("The sum in octal is %o\n",sum);
        printf("The difference in octal is %o\n",dif);
        printf("The sum in hexadecimal is %x\n",sum);
        printf("The difference in hexadecimal is %x\n",dif);
}
