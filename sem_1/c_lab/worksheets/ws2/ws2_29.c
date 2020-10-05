#include<stdio.h>
void main()
{
	int id,h,k=0;
	float wr,rate,pr=0;
	char c='y',t;
	while(c=='y'||c=='Y')
	{
		printf("Enter the ID no. of the employee: ");
		scanf("%d",&id);
		printf("Enter the hourly wage rate of the employee: ");
		scanf("%f",&wr);
		printf("Enter the no of hours worked per week: ");
		scanf("%d",&h);
		if(h>40)
		{
			rate=1.5*wr*h;
			rate=rate-0.03625*rate;
		}
		else
		{
			rate=wr*h;
			rate=rate-0.03625*rate;
		}
		printf("The employee ID is %d\n",id);
		printf("Net pay is Rs.%f\n",rate);
		pr+=rate;
		++k;
		printf("Do you want to continue?(y/n) ");
		scanf("%c%c",&t,&c);
	}
	printf("The payroll is Rs.%f\n",pr);
	printf("The average amount paid Rs.%f\n",pr/k);
}
