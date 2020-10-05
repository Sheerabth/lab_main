#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	int i,j,a,b,c,count[13]={0};
	srand(time(0));
	for(i=0;i<3600;i++)
	{
		a=rand()%6+1;
		b=rand()%6+1;
		c=a+b;
		for(j=2;j<13;j++)
		{
			if(j==c)
			{
				count[j]++;
			}
		}
	}
	for(i=2;i<13;i++)
	{
		printf("\t%d",i);
	}
	printf("\n");
	for(i=2;i<13;i++)
	{
		printf("\t%d",count[i]);
	}
	printf("\n");

}
