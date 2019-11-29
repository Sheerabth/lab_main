#include<stdio.h>
#include<string.h>
void main()
{
    int i,j=0,k=0;
    char str[100],vow[100]={0},con[100]={0};
    printf("Enter the string:\n");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='a'||str[i]=='A'||str[i]=='e'||str[i]=='E'||str[i]=='i'||str[i]=='I'||str[i]=='o'||str[i]=='O'||str[i]=='u'||str[i]=='U')
            vow[j++]=str[i];
        else
            con[k++]=str[i];
    }
    printf("The vowels are %s\n",vow);
    printf("The consonants are %s\n",con);    
}