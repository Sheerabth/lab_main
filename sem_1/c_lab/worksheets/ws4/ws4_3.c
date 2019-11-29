#include<stdio.h>
void main()
{
	int i,amt1=-4000,amt2=0;
	for(i=1;;i++)
	{
		amt2+=0.12*6000;
		amt1+=1000;
		if(amt1>amt2) break;
	}
	printf("Life of machine would be %d\n",i);
}

