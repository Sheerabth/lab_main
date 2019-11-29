#include<stdio.h>
void main()
{
	int n,b[10],i,j;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter their marks:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<10;j++)
		{
			if(j==a[i]/10)
			{
				b[j]++;
			}

		}
	}
	printf("The number of students in the ranges are:\n");
	for(i=0;i<100;i=i+10)
	{
		printf("\t%d-%d",i,i+10);
	}
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf("\t%d",b[i]);
	}
	printf("\n");
}
 
