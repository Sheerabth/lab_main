#include<stdio.h>
void main()
{
        int i,n,sum=0;
        float avg;
        printf("Enter the numbers to be averaged\n");
        for(i=0;;++i)
        {
                scanf("%d",&n);
                if(n==-999)
                {
                        printf("U have reached the end of series\n");
                        break;
                }
                else sum+=n;
        }
        avg=sum/i;
        printf("The average is %f\n",avg);
}
