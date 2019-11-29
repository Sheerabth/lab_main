#include<stdio.h>
int fact(int n)
{
	int t=1;
	for(int i=2;i<=n;i++)
	{
		t*=i;
	}
	return t;
}
void main()
{
	int m,x;
	printf("Enter the value of m: ");
	scanf("%d",&m);
	printf("Enter the value of x: ");
	scanf("%d",&x);
	printf("\t");
	for(int i=0;i<=x;i++) printf("%d\t",i);
	printf("\n"); 
	for(int i=0;i<=m;i++)
	{
		printf("%d\t",i);
		for(int j=0;j<=x;j++)
		{
			if(i>=j)
			printf("%d\t",fact(i)/(fact(j)*fact(i-j)));
		}
		printf("\n");
	}

}
