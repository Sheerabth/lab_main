#include <stdio.h>

int gcd(int n1, int n2)
{
    if (n2 != 0)
    {
        return gcd(n2, n1%n2);
    }
    else 
       return n1;
}

int main()
{
    int n1, n2;
l:    printf("Enter the first number: ");
    scanf("%d",&n1);
    printf("Enter the second number: ");
    scanf("%d",&n2);
    if(n1<=0||n2<=0)
    {
        printf("Enter positive integers\n");
        goto l;
    }
    printf("G.C.D of %d and %d is %d\n",n1,n2,gcd(n1,n2));
    return 0;
}

