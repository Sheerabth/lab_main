#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,k,l,n1,n2,flag=0;
    char str[100],word1[100],word2[100];
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    printf("Enter the word:\n");
    scanf("%s",word1);
    n1=strlen(str);
    n2=strlen(word1);
    for(i=0;i<n1;i=i+k+1)
    {
        if(flag==1)
        {
            i=i-k-1;
        }
        flag=0;
        for(k=0,j=i;str[j]!=' '&&str[j]!='\0';k++,j++)
        {
            word2[k]=str[j];
        }
        word2[k]='\0';
        if(strcmp(word1,word2)==0)
        {
            for(l=j+1;l<n1;l++)
            {
                str[l-k-1]=str[l];
            }
            n1=n1-k-1;
            str[n1]='\0';
            flag=1;
        }
    }
    printf("The modified string is:\n%s\n",str);
}