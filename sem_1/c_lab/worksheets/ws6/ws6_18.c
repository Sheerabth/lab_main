#include<stdio.h>
void main()
{
	int n,i;
	printf("Enter tehe number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n/2;i++)
	{
		a[i]=a[i]^a[n-1-i];
		a[n-1-i]=a[i]^a[n-i-1];
		a[i]=a[i]^a[n-i-1];
	}
	printf("The reversed array is: ");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}
