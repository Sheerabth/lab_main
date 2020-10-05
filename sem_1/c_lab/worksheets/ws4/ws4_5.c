#include<stdio.h>
void main()
{
	int x,rev,i,j;
	printf("Enter a natural number: ");
l:	scanf("%d",&x);
	if(x<1)
	{
		printf("Enter valid natural number\n");
		goto l;
	}
	else
	{
		for(i=x;;i++)
		{
			j=i;
			rev=0;
			while(j!=0)
			{
				rev*=10;
				rev+=j%10;
				j/=10;
			}
			if(rev==i)
			{
				printf("Its nearest palindrome is %d\n",i);
				break;
			}
		}
	}
}
