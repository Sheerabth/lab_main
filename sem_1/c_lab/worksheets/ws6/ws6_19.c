#include<stdio.h>
void main()
{
	int i,j,k,n,l,count[10];
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n],c[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	for(i=0;i<n;i++)
	{
		int b[10]={0};
		while(a[i]>0)
		{
			k=a[i]%10;
			for(j=0;j<10;j++)
			{
				if(k==j)
				{
					b[j]++;
					count[j]++;
					break;
				}
			}
			a[i]/=10;
		}
		printf("The number of digits in %d :\n",c[i]);
		for(l=0;l<10;l++)
		{
			printf("\t%d",l);
		}
		printf("\n");
		for(l=0;l<10;l++)
		{
			printf("\t%d",b[l]);
		}
		printf("\n");
	}
	printf("The number of each digits in total array:\n");
	for(i=0;i<10;i++)
        {
                printf("\t%d",i);
        }
        printf("\n");
        for(i=0;i<10;i++)
        {
  	        printf("\t%d",count[i]);
        }
	printf("\n");
}
