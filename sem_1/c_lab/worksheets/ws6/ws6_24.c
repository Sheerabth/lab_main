#include<stdio.h>
#include<string.h>
void main()
{
	char a[100];
	int score=0,i,n;
	printf("Enter the word: ");
	scanf("%s",a);
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]=='Q'||a[i]=='Z') score+=10;
		else if(a[i]=='J'||a[i]=='X') score+=8;
		else if(a[i]=='K') score+=5;
		else if(a[i]=='F'||a[i]=='H'||a[i]=='V'||a[i]=='W'||a[i]=='Y') score+=4;
		else if(a[i]=='B'||a[i]=='C'||a[i]=='M'||a[i]=='P') score+=3;
		else if(a[i]=='D'||a[i]=='G') score+=2;
		else if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='L'||a[i]=='M'||a[i]=='N'||a[i]=='O'||a[i]=='R'||a[i]=='S'||a[i]=='T') score++;
	}
	printf("The score is %d\n",score);
} 
