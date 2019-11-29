#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n;
    char str[100],ch;
    scanf("%s",str);
    n=strlen(str);
    for(i=0;i<n-2;i=i+2)
    {
        for(j=i+2;j<n;j=j+2)
        {
            if(str[i]>str[j])
            {
                str[i]=str[i]^str[j];
                str[j]=str[i]^str[j];
                str[i]=str[i]^str[j];
            }
        }
    }
    printf("%s\n",str);
    return 0;
}