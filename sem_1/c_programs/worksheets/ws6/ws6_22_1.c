#include<stdio.h>
void main()
{
	int i,sum=0,num;
	printf("Try to guess the number the computer has thought of:\n");
	printf("You can make 9 guesses\n");
	for(i=0;i<9;i++)
	{
		scanf("%d",&num);
		sum+=num;
		printf("You guessed the wrong number!!!\n");
	}
	printf("The correct number is %d\n",55-sum);
}
