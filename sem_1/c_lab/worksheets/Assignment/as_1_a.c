#include<stdio.h>
#include<math.h>

int numpalindrome(int n)
{
    int k=n,i,d=0,num=0;
    while(1)
    {
        i=n/(pow(10,d));
        if(i)
            d++;
        else
            break;
    }
    for(i=1;i<=d;i++)
    {
        num+=pow(10,d-i)*(n%10);
        n/=10;
    }
    if(k==num)
        return 1;
    else
        return 0;
}

void main()
{
    int num,res;
    printf("Enter the number to be checked: ");
l:    scanf("%d",&num);
    if(num<0)
    {
        printf("Enter a positive number: ");
        goto l;
    }
    res=numpalindrome(num);
    if(res)
        printf("The number is a palindrome\n");
    else
        printf("The number is not a palindrome\n");
    
}