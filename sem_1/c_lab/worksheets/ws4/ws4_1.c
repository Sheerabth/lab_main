#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	int n,a;
	srand(time(0));
	a=rand()%100000;
	printf("Enter the number: ");
	scanf("%d",&n);
	if(n>10*a) printf("TOO HIGH\n");
	else if(n<10*a) printf("TOO LOW\n");
	else if(n>5*a||n<5*a) printf("CLOSE\n");
	else if(abs(n-a)<5) printf("TOO CLOSE\n");
}
