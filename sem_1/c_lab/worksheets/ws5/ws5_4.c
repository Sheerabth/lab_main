#include<stdio.h>
void main()
{
	unsigned char x,y;
	printf("Enter the chrachter: ");
	scanf("%c",&x);
	/*printf("%c\n",x);*/
	y=~x;
	for(int i=sizeof(char)*8-1;i>=0;i--)
	{
		if(y>>i&1) printf("1");
		else printf("0");
	}
	printf("\n");
}
