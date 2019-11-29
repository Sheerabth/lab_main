#include<stdio.h>
int main()
{
    int n,i,j,sum=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sum=sum/2;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
    for(i=0,j=0;i<n;)
    {
        j+=a[i];
        i++;
        if(j>sum) break;
    }
    printf("%d\n",i);
}