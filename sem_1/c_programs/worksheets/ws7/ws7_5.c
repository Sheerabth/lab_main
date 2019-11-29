#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
    int i,n,a[26]={0};
    char str[100]={0};
    printf("Enter the text. End the test with a full stop.\n");
    scanf("%[^.]s",str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        str[i]=tolower(str[i]);
    }
    for(i=0;i<n;i++)
    {
        if(isalpha(str[i]));
        a[str[i]-97]++;
    }
    printf("Charachter\toccurances\n");
    for(i=0;i<26;i++)
    {
        printf("%c\t\t%d\n",i+97,a[i]);
    }

}