#include<stdio.h>
#include<string.h>
void main()
{
    char str[100];
    int n,i;
    printf("Enter the string:\n");
    scanf("%s",str);
    n=strlen(str);
    printf("The string is:\n");
    for(i=0;i<n;i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}