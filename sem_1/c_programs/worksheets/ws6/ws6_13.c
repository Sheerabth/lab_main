#include<stdio.h>
void main()
{
	int i,j,n,a[100]={0};
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	for(j=1;j<=i;j++)
	a[i]+=j;
	printf("The series is: \n");
	for(i=1;i<=n;i++) printf("%d: %d\n",i,a[i]);
}
