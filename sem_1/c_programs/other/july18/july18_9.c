#include<stdio.h>
void main()
{
	int n,p,po=1;
	printf("Enter the number: ");
	scanf("%d",&n);
	printf("Enter the number to which %d has to be raised: ",n);
	scanf("%d",&p);
	for(int i=0;i<p;i++)
	po*=n;
	printf("%d raised to the power %d gives %d\n",n,p,po);
}
