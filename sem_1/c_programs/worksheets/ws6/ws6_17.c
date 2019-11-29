#include<stdio.h>
void main()
{
	int n,i,max,count=0;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++) scanf("%d",&n);
	max=a[0];
	for(i=0;i<n;i++)
	if(a[i]>max) max=a[i];
	for(i=0;i<n;i++)
	if(a[i]==max) count++;
	printf("The maximum value is %d and it occurs %d times\n",max,count);
}
