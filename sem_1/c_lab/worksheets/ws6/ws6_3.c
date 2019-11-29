#include<stdio.h>
void jul()
{
	int j,d,m,y,jd=0;
	int md[]={31,28,31,30,31,30,31,31,30,31,30,31};
l1:	printf("Enter the year: ");
	scanf("%d",&y);
	if(y<1)
	{
		printf("Enter valid year:\n");
		goto l1;
	}
	if(y%4==0&&y%100!=0||y%400==0)  md[1]++;
l2:	printf("Enter the month: ");
	scanf("%d",&m);
	if(m<1||m>12)
	{
		printf("Enter valid month:\n");
		goto l1;
	}
l3:	printf("Enter the number of days: ");
	scanf("%d",&d);
	if(d<1||d>md[m-1])
	{
		printf("Enter valid number:\n");
		goto l2;
	}
	for(j=0;j<m-1;j++) jd+=md[j];
	jd+=d;
	printf("The julian days are %d\n",jd);
}
void julrev()
{
	int n,y,i;
	int md[]={31,28,31,30,31,30,31,31,30,31,30,31};
l1:	printf("Enter the year: ");
	scanf("%d",&y);
	if(y<1)
	{
		printf("Enter valid year:\n");
		goto l1;
	}
l2:	printf("Enter the julian day: ");
        scanf("%d",&n);
	if(n<0||n>365&&md[i]==28||n>366&&md[i]==29)
	{
		printf("Enter valid number of days:\n");
		goto l2;
	}
	if(y%4==0&&y%100!=0||y%400==0)  md[1]++;
       	for(i=0;n-md[i+1]>0;i++) n-=md[i];
	printf("The date %d/%d/%d\n",n,i+1,y);
}
void main()
{
	int k;
        printf("Enter\n1.To find Julian days\n2.To find reverse of it\n");
        scanf("%d",&k);
        if(k==1) jul();
        else if(k==2) julrev();
        else printf("Enter valid input\n");
}

