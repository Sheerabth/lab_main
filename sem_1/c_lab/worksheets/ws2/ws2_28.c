#include<stdio.h>
void main()
{
        int temp,n,hd=0,pd=0,cd=0,sum=0;
        float avg;
        printf("Enter the number of data to be entered\n");
        scanf("%d",&n);
        printf("Enter the high temperatures of each day\n");
        int t[n];
        for(int i=0;i<n;i++) scanf("%d",&t[i]);
        for(int i=0;i<n;i++)
        {
                sum+=t[i];
                if(t[i]>=85)
                {
                        hd++;
                        printf("The day with tmeperature %d is a hot day\n$
                }
                else if(t[i]>=60&&t[i]<85)
                {
                        pd++;
                        printf("The day with temperature %d is a pleasant $
                }
                else
                {
                        cd++;
                        printf("The day with temperature %d is a cold day\$
                }
        }
        avg=sum/n;
        printf("The number of hot days are %d\n",hd);
        printf("The number of plesant days are %d\n",pd);
        printf("The number of cold days are %d\n",cd);
        printf("The average temperature is %f\n",avg);
}
