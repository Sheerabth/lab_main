#include<stdio.h>

int fact(int n)
{
    if(n==0)
        return 1;
    else
        return fact(n-1)*n;
}

void main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("The factorial is %d\n",fact(num));
}