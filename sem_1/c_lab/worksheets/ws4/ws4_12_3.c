#include<stdio.h>
void main()
{
	int k=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<=18;j++)
		{
			if((i+j)%2==0&&(j<=i||i+j<=18)&&j>=k) printf("*");
			else printf(" ");
		}
	++k;
	printf("\n");
	}
}
