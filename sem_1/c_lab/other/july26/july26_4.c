#include<stdio.h>
void main()
{
	int n,i,k=1;
	printf("Enter the number: ");
	scanf("%d",&n);
	for(i=1;n>>i>1;i++)
	if(n>>(i-1)!=(n>>i)*2)
	{
		k=0;
		break;
	}
	if(n<0) k=0;
	if(k==0) printf("%d is not a power of 2\n",n);
	else printf("%d is a power of 2\n",n);
}
