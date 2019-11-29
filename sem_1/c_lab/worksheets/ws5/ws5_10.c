#include<stdio.h>
void main()
{
	int n,i;
	printf("Enter the integer: ");
	scanf("%d",&n);
	for(i=32;i>0;i--) if(n>>i) break;
	if(i<=0) printf("No bit is set\n");
	else printf("The highest bit set is %d\n",i);
}

