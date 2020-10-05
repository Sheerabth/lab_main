#include<stdio.h>
void main()
{
	int height,t=0,k,sum=0;
	float avg;
	printf("Enter the heights in inches\n");
	while(1)
	{
		scanf("%d",&k);
		if(k<0) break;
		sum+=k;
		t++;
	}
	avg=(float)sum/t;
	printf("The average height is %f inches\n",avg);
}
