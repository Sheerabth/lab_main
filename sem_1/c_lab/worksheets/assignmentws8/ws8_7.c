#include<stdio.h>
#include<string.h>
void main()
{
    int i,n,k=0,count[100]={0};
    char ch,s[100];
    printf("Enter the string:\n");
    scanf("%[^\n]s",s);
    printf("Enter the charachter to be searched: ");
    scanf("%*c%c",&ch);
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        if(s[i]==ch)
        {
            k=1;
            count[i]=1;
        }
    }
    if(k=0)
        printf("The charachter is not found\n");
    else 
    {
        printf("The charachter is at index(s)\n");
        for(i=0;i<n;i++)
        {
            if(count[i])
                printf("%d\n",i);
        }
    }
}