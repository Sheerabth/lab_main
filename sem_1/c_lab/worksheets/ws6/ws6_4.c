
#include<stdio.h>
void main()
{

	int i,n,k=0;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
	l:	scanf("%d",&a[i]);
		if(a[i]<0)
		{
			printf("Enter valid input:\n");
			goto l;
		}
	}
	for(i=0;i<n-1;i++)
	if(a[i]>a[i+1])
	{
		k=1;
		break;
	}
	if(k==0) printf("They are in ascending order\n");
	else printf("They are not in ascending order\n");
}
