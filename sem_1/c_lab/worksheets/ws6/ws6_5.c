#include<stdio.h>
void main()
{
	int i,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	if(a[i]>a[i+1]) break;
	printf("The index is %d and value is %d\n",i,a[i]);
}
