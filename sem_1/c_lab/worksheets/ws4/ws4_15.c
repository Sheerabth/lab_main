#include<stdio.h>
void main()
{
	int n,i=1,k,e=0,m=0,p=0;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	while(i<=n)
	{
		printf("\nEnglish score of student %d: ",i);
		scanf("%d",&k);
		e+=k;
		printf("Math score of student %d: ",i);
		scanf("%d",&k);
		m+=k;
		printf("Physics score of student %d: ",i);
		scanf("%d",&k);
		p+=k;
		i++;
	}
	printf("\nMean of English= %.3f\n",(float)e/n);
	printf("Mean of Math= %.3f\n",(float)m/n);
	printf("Mean of Physics= %.3f\n",(float)p/n);
}
