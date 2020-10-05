#include<stdio.h>
void main()
{
        int sum=0;
        for(int i=2;i<=30;++i)
        {
                if(i%2==0) sum+=i;
        }
        printf("The sum of even integers from 2 to 30 are %d\n",sum);
}

