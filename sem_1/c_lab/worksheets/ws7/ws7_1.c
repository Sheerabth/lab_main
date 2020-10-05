#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
	char s[100];
	int n,i;
	printf("Enter the string: ");
	scanf("%s",s);
	n=strlen(s);
	printf("The string in uppercase: ");
	for(i=0;i<n;i++)
	printf("%c",toupper(s[i]));
	printf("\n");
	printf("The string in lowercase ");
	for(i=0;i<n;i++)
	printf("%c",tolower(s[i]));
	printf("\n");
}

