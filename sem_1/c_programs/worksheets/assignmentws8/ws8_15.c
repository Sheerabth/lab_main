#include<stdio.h>
#include<string.h>
int main()
{
    int n1,n2,i,j,k;
    char s1[100],s2[100];
    printf("Enter the main string:\n");
    scanf("%s",s1);
    printf("Enter the substring:\n");
    scanf("%s",s2);
    n1=strlen(s1);
    n2=strlen(s2);
    if(n2>n1)
    {
        printf("Not a substring\n");
        return 0;
    }
    for(i=0;i<n1;i++)
    {
        if(s1[i]==s2[0])
        {
            for(j=1,k=i+1;j<n2,k<n1;j++,k++)
            {
                if(s2[j]!=s1[k])
                    break;
            }
        }
    }
    if(j==n2)
        printf("The substring is found\n");
    else 
        printf("The substring is not found\n");
}