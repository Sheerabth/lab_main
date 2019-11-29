#include<stdio.h>
void main()
{
	int n,a[3];
	printf("Enter the number : ");
	scanf("%d",&n);
	for(int i=0;i<3;i++)
	{
		a[i]=n%10;
		n/=10;
	}
	if(a[1]==a[0]+a[2])
	printf("Middle number is the numerical sum of other two digits\n");
	else printf("Middle number is not the numerical sum of other two digits\n");
}
