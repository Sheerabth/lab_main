#include<stdio.h>
void main()
{
        int a,b;
        printf("Enter the first number: ");
        scanf("%d",&a);
        printf("Enter the second number: ");
        scanf("%d",&b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("Value of a after swap is %d\n",a);
	printf("Value of b after swap is %d\n",b);
}

