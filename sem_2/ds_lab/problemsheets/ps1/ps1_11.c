#include<stdio.h>
#include<string.h>
void main()
{
    char name[80];
    int p1,p2,n,i,j,k;
    printf("Enter the name(less than 80 charachters): ");
    scanf("%[^\n]s",name);
    n=strlen(name);
    printf("Short name is %c ",name[i]);
    for(i=0;i<n;i++)
    {
        if(name[i]==' ')
        {
            printf("%c ",name[i+1]);
            break;
        }
    }
    for(j=i+1;j<n;j++)
    {
        if(name[j]==' ')
            break;
    }
    printf("%s\n",name+j+1);
    printf("Abbreviation is %c",name[0]);
    for(i=0;i<n;i++)
    {
        if(name[i]==' ')
            printf("%c",name[i+1]);
    }
    printf("\n");
}