#include<stdio.h>
void main()
{
        int n;
        printf("Enter the integer\n");
        scanf("%d",&n);
        printf("Is %d divisible by 5 and 6? ",n);
        if(n%5==0&&n%6==0) printf("True\n");
        else printf("False\n");
        printf("Is %d divisible by 5 or 6? ",n);
        if(n%5==0||n%6==0) printf("True\n");
        else printf("False\n");
        printf("If %d is divisible by 5 or 6 but not both? ",n);
        if((n%5==0||n%6==0)&&n%30!=0) printf("True\n");
        else printf("False\n");
}
