#include<stdio.h>
void main()
{
    int num[100]={0},count=0,a[3],i,j,k,n;
    printf("Enter the 3 digit number: ");
l:  scanf("%d",&n);
    if(n>999||n<100)
    {
        printf("Enter a valid 3 digit number:\n");
        goto l;
    }
    for(i=0;i<3;i++)
    {
        a[i]=n%10;
        n/=10;
    }
    for(i=0;i<3;i++)
    {
        if(a[i]==0)
            continue;
        for(j=0;j<3;j++)
        {
            if(j!=i)
            {
                for(k=0;k<3;k++)
                {
                    if(k!=j&&k!=i)
                    {
                        num[count++]=a[i]*100+a[j]*10+a[k];
                    }
                }
            }
        }
    }
    for(i=0;i<count-1;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(num[j]==num[i])
            {
                for(k=j;k<count;k++)
                {
                    num[k]=num[k+1];
                }
                j--;
                count--;
            }
        }
    }
    for(i=0;i<count;i++)
        printf("%d\n",num[i]);
}