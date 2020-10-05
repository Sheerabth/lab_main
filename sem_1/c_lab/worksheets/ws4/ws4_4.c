#include<stdio.h>
void main()
{
	int n,sum=0;
	printf("Enter the number: ");
l:	scanf("%d",&n);
	if(n<=0)
	{
		printf("Enter valid positive integer\n");
		goto l;
	}
	else
	{
		printf("Its factors are\n");
		for(int i=1;i<n;i++)
		if(n%i==0)
		{
			printf("%d\n",i);
			sum+=i;
		}
		if(sum==n) printf("Its a perfect number\n");
		else printf("Its not a perfect number\n");
	}
}
