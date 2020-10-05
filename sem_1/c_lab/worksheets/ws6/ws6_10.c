#include<stdio.h>
void main()
{
	int i,j,n,a[100],temp,k=1;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			a[n]=a[i];
			for(j=i;j<n;j++)
			a[j]=a[j+1];
			i--;
		}
		k++;
		if(k>5)
			break;
	}
	printf("The elements of the array are:\n");
	for(i=0;i<n;i++) printf("\t%d",a[i]);
	printf("\n");
}
