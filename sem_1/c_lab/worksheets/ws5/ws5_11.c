#include<stdio.h>
void main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	if(n&n-1||n<2) printf("Not a multiple of 2\n");
	else printf("Multiple of 2\n");
}
