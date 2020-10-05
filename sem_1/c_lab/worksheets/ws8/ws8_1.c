#include<stdio.h>
int fun(int n)
{
	if(n<=0)
		return 0;
	else
		return fun(n-1)+2;
}
void main()
{
	int n;
	printf("Enter the value: ");
	scanf("%d",&n);
	printf("%d\n",fun(n));
}
