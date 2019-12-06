#include<stdio.h>
void main()
{
    int i;
    char s1[20],s2[20],s3[20]={0};
    printf("Enter the first string: ");
    scanf("%s",s1);
    printf("Enter the second string: ");
    scanf("%s",s2);
    for(i=0;s1[i]!='\0'&&s2[i]!='\0';i++)
    {
        if(s1[i]==s2[i])
            s3[i]=s1[i];
    }
    s3[i]='\0';
    if(s3[0]==0)
        printf("There are no common prefixes\n");
    else
        printf("The largest common prefix is %s\n",s3);
}