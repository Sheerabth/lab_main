#include<stdio.h>
#include<math.h>
void main()
{
	int x,n;
	float ln=0;
l:	printf("Enter the number: ");
	scanf("%d",&x);
	printf("Enter the number till which it has to be calculated: ");
	scanf("%d",&n);
	if(n<=0||x<=0)
	{
		printf("Enter valid positive numbers\n");
		goto l;
	}
	for(int i=1;i<=n;i++)
	ln+=0.5*(pow(((float)(x-1)/x),i));
	printf("The natural logarithm of the number is %.3f\n",ln);
}

