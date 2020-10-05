#include<stdio.h>
#include<string.h>
void main()
{
    char str[100],ch;
    int n,i;
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    n=strlen(str);
    for(i=0;i<n/2;i++)
    {
        ch=str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=ch;
    }
    printf("The reversed string is %s\n",str);
}