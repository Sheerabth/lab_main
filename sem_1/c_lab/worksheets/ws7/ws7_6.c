#include<stdio.h>
#include<string.h>
void main()
{
	int len,i,count=0;
	char str[100];
	printf("Enter the line:\n");
	scanf("%[^\n]s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]==' '||str[i]==','||str[i]=='.')
			count++;
	}
	if(str[len-1]!='.')
		count++;
	printf("The number of words are %d\n",count);
}
