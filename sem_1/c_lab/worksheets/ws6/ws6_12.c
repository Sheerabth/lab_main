#include<stdio.h>
#include<string.h>
void main()
{
	int i,n;
	char a[100];
	printf("Enter the string: ");
	scanf("%s",a);
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]=='z') a[i]='a';
		else if(a[i]=='Z') a[i]='A';
		else a[i]++;
	}
	printf("%s\n",a);
}
