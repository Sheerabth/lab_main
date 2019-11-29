#include<stdio.h>
#include<ctype.h>
void main()
{
    int i;
    char str[100];
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    for(i=0;i<str[i]!='\0';i++)
    {
        if(islower(str[i]))
            str[i]=toupper(str[i]);
        else if(isupper(str[i]))
            str[i]=tolower(str[i]);   
    }
    printf("The toggled string is %s\n",str);
}