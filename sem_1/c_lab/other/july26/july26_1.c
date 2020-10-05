#include<stdio.h>
void main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	for(int i=sizeof(int)*8-1;i>=0;i--)
	{
		if((n>>i)&1==1)printf("1");
		else printf("0");
	}
	printf("\n");
}
