#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int main()
{
    long int i,j,k=1;
    bool prime[100];
    memset(prime,true,sizeof(prime));
    for(i=2;i*i<=1000;i++)
    {
        if(prime[i]==true)
        {
            for(j=i*i;j<=1000;j+=i)
                prime[j]=false;
        }
    }
    for(i=2;i<1000;i++)
    {
        if(prime[i]==true)
            printf("%ld\n",i);
    }
}