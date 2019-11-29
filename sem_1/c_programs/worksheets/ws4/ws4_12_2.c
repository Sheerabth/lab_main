#include<stdio.h>
void main()
{
	int k=10;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(j<=i) printf(" ");
			else printf("*");
		}
		printf("\n");
		k++;
	}
}
