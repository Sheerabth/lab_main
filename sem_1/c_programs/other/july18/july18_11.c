#include<stdio.h>
int prime(int k)
{
	int i;
	if(k==1) return 0;
	else if(k==2) return 1;
	else
	{
		for(i=2;i<k;i++)
		if(k%i==0)
		{
			return 0;
			break;
		}
	}
	if(i>k) return 1;
}
void main()
{
	int p,mer=1;
	printf("Enter a prime number: ");
	l:	scanf("%d",&p);
		/*printf("%d\n",prime(p));*/
		if(prime(p)==0)
		{
			printf("Enter a valid prime number: ");
			goto l;
		}
		else
		{
		for(int i=0;i<p;i++)
		mer*=2;
		printf("The mersenne number of %d is %d\n",p,mer-1);
		}
}
