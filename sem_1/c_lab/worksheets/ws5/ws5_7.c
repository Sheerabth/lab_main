#include<stdio.h>
void main()
{
	int x,y,max;
	printf("Enter the two numbers\n");
	scanf("%d%d",&x,&y);
	max=x^((x^y)&-(x<y));
	printf("Maximum number is %d\n",max);
}
