#include<stdio.h>
void main()
{
	float amt,bal=0;
	char ch;
	printf("\t***** ****** ** ******\n");
	printf("Amount\tTransaction Type\n");
	while(bal>=0)
	{
		scanf("%f	%c",&amt,&ch);
		if(ch=='d') bal+=amt;
		else if(ch=='w') bal-=amt;
		else printf("Enter valid transaction type\n");
	}
	printf("Sorry your account is in lesser the minimum balance\n");
	printf("Your current balance amount is Rs.%.2f\n",bal);
}
