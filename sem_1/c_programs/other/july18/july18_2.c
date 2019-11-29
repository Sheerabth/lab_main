#include<stdio.h>
void main()
{
        int weight,t=0,k,sum=0;
        float avg;
        printf("Enter the weights in pounds\n");
        while(1)
        {
                scanf("%d",&k);
                if(k<0) break;
                sum+=k;
                t++;
        }
        avg=(float)sum/t;
        printf("The average weight is %f pounds\n",avg);
}

