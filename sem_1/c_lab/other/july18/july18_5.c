#include<stdio.h>
void main()
{
	for(int i=1;i<=20;i++)
	for(int j=-5;j<=5;j++)
	for(int k=3;k<=17;k++)
	printf("(6x%d^3)-(5x%dy^2)-(4x%d)+2=%d\n",i,j,k,6*i*i*i-5*j*j-4*k+2);
}
