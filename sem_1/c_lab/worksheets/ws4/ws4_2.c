#include<stdio.h>
void main()
{
	int n,m;
	printf("Enter the value whose table is to be printed: ");
	scanf("%d",&m);
	printf("Enter the number till the table has to be printed: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	printf("%d\tx\t%d\t=\t%d\n",m,i,m*i);
}
