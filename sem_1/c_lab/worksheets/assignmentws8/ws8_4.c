#include<stdio.h>
#include<ctype.h>
void main()
{
    char low[100]={0},up[100]={0},str[100];
    int i,j=0,k=0;
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    for(i=0;str[i]!='\0';i++)
    {
        low[j++]=tolower(str[i]);
        up[k++]=toupper(str[i]);
    }
    printf("The string in lowercase is %s\n",low);
    printf("The string in uppercase is %s\n",up);
}