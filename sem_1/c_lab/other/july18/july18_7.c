#include<stdio.h>
void main()
{
	int n,fact=1;
	printf("Enter the number: ");
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	fact*=i;
	printf("The factorial is %d\n",fact);
}
