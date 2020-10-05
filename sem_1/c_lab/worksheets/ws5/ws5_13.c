#include<stdio.h>
void main()
{
	int i,j,n;
	printf("Enter the integer: ");
	scanf("%d",&n);
	printf("Enter the bits to be swapped\n");
	scanf("%d%d",&i,&j);
	if(((n>>i-1)&1)==((n>>j-1)&1)) printf("Both bits are same\n");
	else if((n>>i-1)&1)
	{
		n=n&(~(1<<i-1));
		n=n|(1<<j-1);
	}
	else
	{
		n=n&(~(1<<j-1));
                n=n|(1<<i-1);
	}
	printf("The number after swapping is %d\n",n);
}

