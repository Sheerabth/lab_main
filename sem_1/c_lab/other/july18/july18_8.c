#include<stdio.h>
void main()
{
	int n,m,sum=0;
	l:	printf("Enter the first number: ");
		scanf("%d",&n);
		printf("Enter the second integer: ");
		scanf("%d",&m);
		if(n>m)
		{
			printf("n should be less than m\n");
			goto l;
		}
		else
		for(int i=n;i<=m;i++)
		sum+=i;
		printf("The sum of integers from %d to %d is %d\n",n,m,sum);
}
