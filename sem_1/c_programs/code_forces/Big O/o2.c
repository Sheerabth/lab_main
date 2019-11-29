#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int i,j,n,count=0;
    char s[1000];
    scanf("%[^\n]s",s);
    n=strlen(s);
    for(i=1;i<n-4;i=i+3)
    {
        for(j=i+3;j<n-1;j=j+3)
        {
            if(s[i]==s[j])
            {
                s[j]='1';
            }
        }
    }
   for(i=1;i<n-1;i=i+3)
   {
        if(isalpha(s[i]))
            count++;
   }
   printf("%d\n",count);
}