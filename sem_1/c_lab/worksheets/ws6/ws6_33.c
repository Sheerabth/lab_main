#include<stdio.h>
void main()
{
	int i;
	char name[]="VSK sir",ans[100];
	printf("Who is our computer sir?\n");
	scanf("%[^\n]s",ans);
	for(i=0;i<8;i++)
	{
		if(name[i]!=ans[i]) break;
	}
	if(i==8) printf("Good\n");
	else printf("Wrong\n");
}
