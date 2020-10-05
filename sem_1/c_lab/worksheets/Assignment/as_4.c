#include<stdio.h>

int sumfun(int n)
{
    if(n==0)
        return 0;
    else
        return sumfun(n-1)+n;
}

void main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("The result is %d\n",sumfun(num));
}