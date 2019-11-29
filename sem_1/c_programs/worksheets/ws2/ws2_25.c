#include<stdio.h>
void main()
{
        int sum=0,digit,n;
        printf("Enter the number\n");
        scanf("%d",&n);
        while(n>0)
        {
                digit=n%10;
                printf("%d\n",digit);
                sum+=digit;
                n/=10;
        }
        if(sum%9==0) printf("The number is divisible by 9\n");
        else printf("the number is not divisible by 9\n");
}
