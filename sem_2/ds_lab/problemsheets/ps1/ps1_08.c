#include<stdio.h>
void main()
{
    int i,j,n,dpt;
    printf("Enter the number of employees: ");
    scanf("%d",&n);
    char name[n][20];
    int wpt[n],pro[n][5];
    for(i=0;i<n;i++)
    {
        printf("Enter the name of employee\n");
        scanf("%*c%s",name[i]);
        printf("Enter the employee's daily production\n");
        wpt[i]=0;
        for(j=0;j<5;j++)
        {
            scanf("%d",&pro[i][j]);
            wpt[i]+=pro[i][j];
        }
    }
    for(i=0;i<n;i++)
        printf("The weekly production total of %s is %d\n",name[i],wpt[i]);
    for(i=0;i<5;i++)
    {
        dpt=0;
        for(j=0;j<n;j++)
            dpt+=pro[j][i];
        printf("The production total in day %d is: %d\n",i+1,dpt);
    }
}