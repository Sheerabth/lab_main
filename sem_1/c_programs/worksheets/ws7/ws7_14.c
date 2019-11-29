#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,n;
    char str[100];
    printf("Enter the string:\n");
    scanf("%s",str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        if(str[i]==' '&&str[i+1]==' ')
        {
            for(j=i+2;j<n;j++)
            {
                str[j-1]=str[j];
            }
            n--;
            i--;
        }
    }
    printf("The modified string is %s\n",str);
}