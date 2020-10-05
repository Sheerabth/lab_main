#include<stdio.h>
void main()
{
	int k,count,n,i,j;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the number: ");
	scanf("%d",&k);
	int a[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(a[i]>a[j])
	{
		a[i]=a[i]^a[j];
		a[j]=a[i]^a[j];
		a[i]=a[i]^a[j];
	}
	/*for(i=0;i<n;i++) printf("%d",a[i]);*/
	for(i=0;i<n-1;i=i+count)
	{
		count=1;
		for(j=i+1;j<n;j++)
		if(a[i]==a[j]) count++;
		/*printf("\n\n%d\n",count);*/
	 	if(count>n/k) printf("\n%d appears more than %d times\n",a[i],n/k);
	}
}
