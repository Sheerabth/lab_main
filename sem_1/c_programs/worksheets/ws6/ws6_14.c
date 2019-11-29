#include<stdio.h>
void main()
{
	int i,j,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n+1];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	a[n]=a[0];
	for(i=0;i<=n;i++)
	a[i]=a[i+1];
	for(i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}
