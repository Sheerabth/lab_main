#include<stdio.h>
#include<string.h>

int Isvowel(char *p)
{
    int count=0,i,n=strlen(p);
    for(i=0;i<n;i++)
    {
        if(p[i]=='a'||p[i]=='A'||p[i]=='e'||p[i]=='E'||p[i]=='i'||p[i]=='I'||p[i]=='o'||p[i]=='O'||p[i]=='u'||p[i]=='U')
        {
            count++;
        }
    }
    return count;
}

void main()
{
    char str[100];
    printf("Enter the string:\n");
    scanf("%[^\n]s",str);
    printf("The number of vowels are %d\n",Isvowel(str));
}