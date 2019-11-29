#include<stdio.h>

int func(int n)
{
    if(n==0)
        return 1;
    else
        return (func(n-1)*n)+n;
}

void main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("The result is %d\n",func(num));
}