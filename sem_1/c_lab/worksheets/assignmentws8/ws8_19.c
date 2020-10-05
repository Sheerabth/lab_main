#include<stdio.h>
#include<string.h>
void main()
{
        int i,j,count;
        char str[100],ch;
        printf("Enter the string:\n");
        scanf("%[^\n]s",str);
        for(i=0;str[i]!='\0';i=i+count+1)
        {
                count=0;
                for(j=i;str[j]!=' '&&str[j]!='\0';j++)
                        count++;
                for(j=0;j<count/2;j++)
                {
                        ch=str[i+j];
                        str[i+j]=str[i+count-1-j];
                        str[i+count-1-j]=ch;
                }
        }
        printf("The string is \n%s\n",str);
}
