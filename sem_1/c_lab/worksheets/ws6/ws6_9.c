#include<stdio.h>
void main()
{
	int k,i,j,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elemets:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(a[i]==a[j])
	{
		for(k=j;k<n-1;k++)
		a[k]=a[k+1];
		n--;
		j--;
	}
	printf("The number of elements are:\n");
	for(i=0;i<n;i++) printf("%d\t",a[i]);
}
