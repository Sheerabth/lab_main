#include<stdio.h>
#include<string.h>
void main()
{
    char str[100];
    int n,i,j;
    printf("Enter the string:\n");
    scanf("%s",str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
            printf("%c",str[j]);
        printf("\n");
    }
}