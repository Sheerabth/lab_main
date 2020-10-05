#include<stdio.h>
#include<string.h>
void sort(char *s,int len)
{
    int i,j;
    for(i=0;i<len-1;i++)
    {
        for(j=i;j<len;j++)
        {
            if(s[i]>s[j])
            {
                s[i]=s[i]^s[j];
                s[j]=s[i]^s[j];
                s[i]=s[i]^s[j];
            }
        }
    }
}
void main()
{
    int i=0,k=0,j=0,n1,n2,n3;
    char s1[10],s2[10],s3[20],s4[20]={0};
    printf("Enter the first string:\n");
    scanf("%s",s1);
    printf("Enter the second string:\n");
    scanf("%s",s2);
    printf("Enter the resultant string:\n");
    scanf("%s",s3);
    n1=strlen(s1);
    n2=strlen(s2);
    n3=strlen(s3);
    sort(s1,n1);
    sort(s2,n2);
    sort(s3,n3);
    for(i=0,j=0;i<n1&&j<n2;)
    {
        if(s1[i]<s2[j])
            s4[k++]=s1[i++];
        else if(s2[j]<s1[i])
            s4[k++]=s2[j++];
        else if(s1[i]==s2[j])
        {
            s4[k++]=s1[i++];
            j++;
        }
    }
    if(i<n1)
    {
        while(i<n1)
            s4[k++]=s1[i++];
    }
    if(j<n2)
    {
        while(j<n2)
            s4[k++]=s2[j++];
    }
    s4[k]='\0';
    if(strcmp(s3,s4)==0)
        printf("It is a valid shuffle\n");
    else
        printf("Not a valid shuffle\n");
}