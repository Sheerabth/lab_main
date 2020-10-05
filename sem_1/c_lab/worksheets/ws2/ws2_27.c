#include<stdio.h>
#include<math.h>
void main()
{
        int range,N,sum=0,sum2=0,max,min;
        float avg,std;
        printf("Enter the number of data to be entered\n");
        scanf("%d",&N);
        printf("Enter the values\n");
        int num[N];
        for(int i=0;i<N;i++) scanf("%d",&num[i]);
         min=max=num[0];
        for(int i=0;i<N;i++)
        {
                if(num[i]<min) min=num[i];
                if(num[i]>max) max=num[i];
        }

        for(int i=0;i<N;i++)
        {
                sum+=num[i];
                sum2+=num[i]*num[i];
        }
        range=max-min;
        avg=sum/N;
        std=sqrt(sum2/N-avg*avg);
        printf("The range is %d\n",range);
        printf("The standard deviation is %f\n",std);
}
