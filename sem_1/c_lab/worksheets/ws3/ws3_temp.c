#include<stdio.h>
#include<limits.h>
/*No Offence*/
void main()
{
	int i,s,l,n,small=INT_MAX,large=0;
	printf("Enter sample integers, negative integers when done\n");
	for(i=1;;i++)
	{
		scanf("%d",&n);
		if(n<0) break;
		else
		{
			if(n<small)
			{
				small=n;
				s=i;
			}
			else if(n>large)
			{
				large=n;
				l=i;
			}
		}
	}
	printf("The smallest number was %d and it is data item # %d.\n",small,s);
	printf("The larget number was %d and it is data item # %d.\n",large,l);
}
