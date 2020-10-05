#include<stdio.h>
#include<string.h>
void main()
{
    char str[100],ch;
    int n,i,j,count,max=0;
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=0;j<n;j++)
        {
            if(str[i]==str[j])
                count++;
        }
        if(count>max)
        {
            max=count;
            ch=str[i];

        }
    }
    printf("The charahcter %c occurs the most number of times, %d times\n",ch,max);
}