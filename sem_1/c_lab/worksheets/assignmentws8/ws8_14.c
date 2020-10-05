#include<stdio.h>
#include<string.h>
void main()
{
    char str[100],ch;
    int n,i,j,k=0;
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    n=strlen(str);
    printf("Enter the charachter to be removed: ");
    scanf("%*c%c",&ch);
    for(i=0;i<n;i++)
    {
        if(str[i]==ch)
        {
            k=1;
            for(j=i;j<n-1;j++)
            {
                str[j]=str[j+1];
            }
            str[n-1]='\0';
            n--;
            i--;
        }
    }
    if(!k)
        printf("Charachter not found\n");
    else
        printf("The final string is %s\n",str);
}