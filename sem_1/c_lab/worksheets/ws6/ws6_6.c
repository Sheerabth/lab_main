#include<stdio.h>
void main()
{
	int n,i,j,k=0,sum;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				a[i]+=a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
	}
	printf("Enter the sum of number: ");
	scanf("%d",&sum);
	i=0;
	j=n-1;
	while(i<j)
	{
		if(a[i]+a[j]==sum)
		{
			k=1;
			break;
		}
		else if(a[i]+a[j]<sum) i++;
		else j--;
	}

	if(k==1)
	printf("The sum is with %d and %d\n",a[i],a[j]);
	else
	printf("Elements not found\n");
}
