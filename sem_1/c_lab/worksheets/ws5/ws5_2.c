#include<stdio.h>
void binary(int n)
{
	for(int i=sizeof(int)*8-1;i>=0;i--)
	{
		if(n>>i&1) printf("1");
		else printf("0");
	}
	printf("\n");
}
void main()
{
	int a;
	printf("Enter the number: ");
	scanf("%d",&a);
	binary(a);
	binary(a/16);
}
