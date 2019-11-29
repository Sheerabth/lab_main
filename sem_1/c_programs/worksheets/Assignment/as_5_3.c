#include<stdio.h>

int fibonacci(int n)
{
    if (n==0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void main()
{
    int i,n;
    printf("Enter the number of terms in the fibonacci series to be printed: ");
    scanf("%d",&n);
    printf("Fibonacci series:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",fibonacci(i));
    }
    printf("\n");
}