#include<stdio.h>
#include<string.h>
void main()
{
        int n1,n2,i,j,k;
        char s1[100],s2[100];
        printf("Eneter the first string:\n");
        scanf("%s",s1);
        printf("Enter the second string:\n");
        scanf("%s",s2);
        n1=strlen(s1);
        n2=strlen(s2);
        for(i=0;i<n1;i++)
        {
                for(j=0;j<n2;j++)
                {
                        if(s1[i]==s2[j])
                        {
                                for(k=j;k<n2-1;k++)
                                {
                                        s2[k]=s2[k+1];
                                }
                                s2[n2-1]='\0';
                                j--;
                                n2--;
                        }
                }
        }
        printf("The new string is %s\n",s2);
}