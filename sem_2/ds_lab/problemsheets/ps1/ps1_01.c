#include<stdio.h>
#include<math.h>
void main()
{
        int i,n;
        printf("Enter the number of elements: ");
        scanf("%d",&n);
        int a[n],sum=0;
        float temp=0,avg=0,sd=0;
        printf("Enter the numbers: \n");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        for(i=0;i<n;i++)
                sum+=a[i];
        avg=(float)sum/n;
        for(i=0;i<n;i++)
                temp+=(a[i]-avg)*(a[i]-avg);
        sd=sqrt(temp/(sum-1));
        printf("The average is %f\n",avg);
        printf("The standard deviation is %f\n",sd);
        int num,count=0;
        printf("Enter the number to be compared: ");
        scanf("%d",&num);
        for(i=0;i<n;i++)
        {
                if(a[i]>=num)
                        count++;
        }
        printf("The number of integers greater than or equal to the given number is %d\n",count);
}
