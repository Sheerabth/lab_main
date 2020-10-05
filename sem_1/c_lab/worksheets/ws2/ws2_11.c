#include<stdio.h>
void main()
{
        int count=0,d,m,y,i;
        int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
        printf("Enter the day\n");
        scanf("%d",&d);
        printf("Enter the month\n");
        scanf("%d",&m);
        printf("Enter the year\n");
        scanf("%d",&y);
        for(i=0;i<m-1;i++)
        {
                if(y%4==0&&y%100!=0||y%100==0&&y%400==0) a[1]=29;
                count+=a[i];
        }
        count+=d;
        printf("The day number is %d\n",count);
}
