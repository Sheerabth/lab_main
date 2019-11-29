#include<stdio.h>
#include<ctype.h>
void main()
{
    int i;
    char str[100];
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='a'||str[i]=='A'||str[i]=='e'||str[i]=='E'||str[i]=='i'||str[i]=='I'||str[i]=='o'||str[i]=='O'||str[i]=='u'||str[i]=='U')
            str[i]='*';
        else if(isalpha(str[i]))
            str[i]='#';
    }
    printf("The string is %s\n",str);   
}