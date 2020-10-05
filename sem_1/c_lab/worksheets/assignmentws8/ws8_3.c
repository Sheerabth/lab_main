#include<stdio.h>
#include<ctype.h>
void main()
{
    char str[100];
    int i,low=0,up=0,spl=0;
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    for(i=0;str[i]!='\0';i++)
    {
        if(islower(str[i]))
            low++;
        else if(isupper(str[i]))
            up++;
        else
            spl++;
    }
    printf("The number of lowercase charachters are %d\n",low);
    printf("The number of uppercase charachter are %d\n",up);
    printf("The number of special charachters are %d\n",spl);
}