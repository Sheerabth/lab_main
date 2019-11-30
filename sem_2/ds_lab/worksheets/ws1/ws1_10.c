#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    int i,j,k,n1,n2,n,p,b=0;
    char str[80],s1[10],s2[10];
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    printf("Enter the substring to be replaced:\n");
    scanf("%*c%[^\n]s",s1);
    printf("Enter the substring to replace:\n");
    scanf("%*c%[^\n]s",s2);
    n2=strlen(s2);
    n=strlen(str);
    n1=strlen(s1);
    for(k=0;k<10;k++)
    {
        for(i=0,j=0;i<n;i++)
        {
            if(str[i]==s1[j])
            {
                j++;
                if(j==n1)
                {
                    p=i;
                    break;
                }
            }
            else
            j=0;
        }
        if(j!=n1)
            continue;
        b=1;
        if(n2>n1)
        {
            for(i=n-1;i>p;i--)
                str[i+n2-n1]=str[i];
        }
        else if(n2<n1)
        {
            for(i=p+1;i<n;i++)
                str[i-n1+n2]=str[i];
        }
        for(i=0;i<n2;i++)
            str[i+p-n1+1]=s2[i];
        n+=n2-n1;
        str[n]='\0';
    }
    if(b==0)
        printf("The substring is not found\n");
    else
        printf("The modified string is %s\n",str);
}