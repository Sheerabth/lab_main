#include<stdio.h>
void main()
{
	int a,b;
	printf("Enter the 1st number: ");
	scanf("%d",&a);
	printf("Enter the 2nd number: ");
	scanf("%d",&b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("Value of 1st number after swap: %d\n",a);
	printf("Value of 2nd number after swap: %d\n",b);
}
