#include<stdio.h>
void main()
{
	int n,i;
	printf("Enter the integer: ");
	scanf("%d",&n);
	for(i=31;i>0;i--) if((n>>i)&1) break;
	printf("The number of leading zeros are %d\n",31-i);
	for(i=0;i<32;i++) if((n>>i)&1) break;
	printf("The number of trailing zeros are %d\n",i);
} 
