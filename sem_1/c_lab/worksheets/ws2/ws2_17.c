#include<stdio.h>
void main()
{
	int i,j;
	float p=0,n;
	printf("Enter the number to compare: ");
	scanf("%f",&n);
	for(i=1,j=1;;i++,j+=2)
	{
		if(i%2==0) p-=(float)4/j;
		else p+=(float)4/j;
		printf("%d:	%f\n",i,p);
		if((p-n<=0.000001)&&(p-n>0)) break;
	}
}
