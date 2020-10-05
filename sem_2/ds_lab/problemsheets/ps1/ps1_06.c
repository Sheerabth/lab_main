#include<stdio.h>
#include<string.h>
void main()
{
    int n,num;
    printf("Enter any odd number of rows and columns: ");
l:  scanf("%d",&n);
    if(n%2==0)
    {
        printf("Enter an odd number:\n");
        goto l;
    }
    int ms[n][n];
    int i=n/2,j=n-1;
    memset(ms,0,sizeof(ms));
    for(num=1;num<=n*n;)
    {
        if(i==-1&&j==n)
        {
            i=0;
            j=n-2;
        }
        else
        {
            if(j==n)
                j=0;
            if(i<0)
                i=n-1;
        }
        if(ms[i][j])
        {
            j-=2;
            i++;
            continue;
        }
        else
            ms[i][j]=num++;
        i--;
        j++;
    }
    printf("The majic square is\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%3d",ms[i][j]);
        printf("\n");
    }
}