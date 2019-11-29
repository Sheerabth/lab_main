#include<stdio.h>
void main()
{
	int y;
	float x;
	printf("\t");
	for(x=5.5;x<=12.5;x+=0.5) printf("%.2f\t",x);
	printf("\n");
	for(y=1;y<=6;y++)
	{
		printf("%d\t",y);
		for(x=5.5;x<=12.5;x+=0.5)
		printf("%.2f\t",2+y+0.5*x);
		printf("\n");
	}
}

