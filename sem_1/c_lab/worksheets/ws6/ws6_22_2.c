#include<stdio.h>
void main()
{
	int i,num,a[11]={0};
	printf("Guess the number the computer has thought of:\n");
	printf("You are allowed to make 9 guess\n");
	for(i=0;i<9;i++)
	{
		scanf("%d",&num);
		printf("You guessed the wrong number!!!\n");
				a[num]=num;
	}
	printf("The correct number is: ");
	for(i=1;i<11;i++)
	{
		if(a[i]==0)printf("%d",i);
	}
	printf("\n");
}
