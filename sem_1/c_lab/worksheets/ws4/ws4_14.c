#include<stdio.h>
void main()
{
	int st,n,i,j;
	printf("Calender of a specific monthn will be shown.\n");
l:	printf("Which day of the week does the month start?\n");
	printf("Input figure among the following figures.\n");
	printf("0:Sun, 1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat,\n");
	scanf("%d",&st);
	printf("How many days does the month have?\n");
	scanf("%d",&n);
	if(st<0||st>6||n<1||n>31)
	{
		printf("Enter valid input\n");
		goto l;
	}
	else
	{
		printf("Su\tMo\tTu\tWe\tTh\tFr\tSa\n");
		for(i=1;i<=st;i++) printf("\t");
		for(j=1;j<=n;j++)
		{
			printf("%d\t",j);
			if(i%7==0) printf("\n");
			i++;
		}
	}
	printf("\n");
}

