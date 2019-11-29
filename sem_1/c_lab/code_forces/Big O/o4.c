#include<stdio.h>
int main()
{
    long long int i,j,n,k;
    scanf("%lld",&n);
    long long int a[n];
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(i=0;i<n;i++)
    {
        k=1;
       // printf("i=%lld\tj=%lld\tk=%lld\n",i,j,k);
        for(j=2;j<a[i];j++)
        {
            printf("i=%lld\tj=%lld\tk=%lld\n",i,j,k);
            if(a[i]%j==0)
                k--;
        }
        if(k==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}