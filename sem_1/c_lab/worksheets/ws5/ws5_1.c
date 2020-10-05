#include<stdio.h>
void main()
{
	int a,b;
	printf("Enter the first number: ");
	scanf("%d",&a);
	printf("Enter the second number: ");
        scanf("%d",&b);
	printf("a & b = %d\n",a&b);
	printf("a | b = %d\n",a|b);
	printf("a ^ b = %d\n",a^b);
	printf("a>>1 = %d\nb>>1 = %d\n",a>>1,b>>1);
	printf("a<<1 = %d\nb<<1 = %d\n",a<<1,b<<1);
	printf("~a = %d\n~b = %d\n",~a,~b);
}
