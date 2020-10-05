#include<stdio.h>
#include<string.h>
void main()
{
	int n,res;
	char s1[100],s2[100];
	printf("Enter the first string:\n");
	scanf("%s",s1);
	printf("Enter the second string:\n");
	scanf("%s",s2);
	printf("Enter the number of charachters to check: ");
	scanf("%d",&n);
	res=strncmp(s1,s2,n);
	if(res>0)
		printf("The first string is greater than the second string\n");
	else if(res<0)
		printf("The first string is less than the second string\n");
	else
		printf("Both strings are equal\n");
}


