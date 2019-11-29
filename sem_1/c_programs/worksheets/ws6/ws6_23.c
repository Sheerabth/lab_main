#include<stdio.h>
void main()
{
	int d,m,y,k=0,dayno=0;
l1:	printf("Enter the year: ");
	scanf("%d",&y);
	if(y<0)
	{
		printf("Enter proper year:\n");
		goto l1;
	}
	if(y%4==0&&y%100!=0||y%400==0) k=1;
l2:	printf("Enter the month number: ");
	scanf("%d",&m);
	if(m<1||m>12)
	{
		printf("Enter proper month:\n");
		goto l2;
	}
l3:	printf("Enter the days: ");
	scanf("%d",&d);
	if(d<1||(k==0&&d>365)||(k==1&&d>366))
	{
		printf("Enter proper date\n");
		goto l3;
	}
	dayno=(m-1)*31+d;
	if(m>2)
	{
		dayno=dayno-((4*m+23)/10);
		if(k==1) dayno++;
	}
	printf("The day number is %d\n",dayno);
}

