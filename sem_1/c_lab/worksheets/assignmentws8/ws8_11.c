#include<stdio.h>
#include<string.h>
#include<math.h>
void main()
{
    char str[100];
    int n,i,ans=0;
    printf("Enter the string:\n");
    scanf("%s",str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        ans+=pow(10,n-i-1)*(str[i]-48);
    }
    printf("The answer is %d\n",ans);
}