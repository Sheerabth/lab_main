#include<stdio.h>
void main()
{
	int n,a[100],i;
	printf("Enter the number of elements: ");
l:	scanf("%d",&n);
	if(n%2!=0)
	{
		printf("Enter even number of inputs\n");
		goto l;
	}
	printf("Enter the elements:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i=i+2)
	{
		printf("\t%d",a[i]*a[i+1]);
	}
	printf("\n");
}
