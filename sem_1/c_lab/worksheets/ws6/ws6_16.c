#include<stdio.h>
void main()
{
	int n,i,min,max;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[i];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	min=max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<min) min=a[i];
		else if(a[i]>max) max=a[i];
	}
	printf("The minimum value is %d\n",min);
	printf("The maximum value is %d\n",max);
}
