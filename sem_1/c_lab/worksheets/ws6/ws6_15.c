#include<stdio.h>
void main()
{
	int i,j,m,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n+1];
	printf("Enter the number of times to cycle: ");
	scanf("%d",&m);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	{
		a[n]=a[0];
		for(j=0;j<=n;j++)
		a[j]=a[j+1];
	}
	printf("The result is:\n");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}
