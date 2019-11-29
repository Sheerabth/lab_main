#include<stdio.h>
#include<string.h>
void main()
{
    int count=0,i;
    char ch,s[100];
    printf("Enter the line that ends with a full stop:\n");
    scanf("%[^'.']s",s);
    printf("Enter the charachter:\n");
    scanf("%*c*c*c%c",&ch);
    for(i=0;s[i]!='\0';i++)
    {
        if(ch==s[i])
            count++;
    }
    if(count==0)
        printf("The charachter is not there\n");
    else 
        printf("The number of occurances are %d\n",count);
}