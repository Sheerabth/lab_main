#include<stdio.h>
void main()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<19;j++)
		{
			if((i<=j&&j<=9)||(i+j<=18&&j>=9)) printf("*");
			else printf(" ");
		}
	printf("\n");
	}
}
