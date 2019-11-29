#include<stdio.h>
void main()
{
	int a[100],i,n,min,max,sum=0;
	float avg;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the temperatures:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	min=max=a[0];
	for(i=0;i<n;i++)
	{
		sum+=a[i];
		if(a[i]<min) min=a[i];
		else if(a[i]>max) max=a[i];
	}
	avg=sum/n;
	printf("The maximum number is %d\n",max);
	printf("The minimum number is %d\n",min);
	printf("The average is %.2f\n",avg);
}

