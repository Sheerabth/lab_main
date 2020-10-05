#include<stdio.h>
void main()
{
        int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
        int month=1,date,year,num,m1,a1,ns,as,f;
        printf("Enter the year\n");
        scanf("%d",&year);
        printf("Enter the no. of day from the beginning\n");
        scanf("%d",&num);
        for(int i=0;num>a[i];i++)
        {
                if(year%4==0)
                {
                        a[1]=29;
                }
                num-=a[i];
                month++;
        }
        date=num;
        printf("The date is %d/%d/%d\n",date,month,year);
        if(month==1)
        {
                m1=13;
                a1=year-1;
        }
        else if(month==2)
        {
                m1=14;
                a1=year-1;
        }
        else
        {
                m1=month;
                a1=year;
        }
        as=a1/100;
        ns=a1-(as*100);
        f=date+ns+(ns/4)+(5*as)+(as/4)+((13*m1)/5)+1;
        f%=7;
        switch(f)
        {
                case 0: printf("The day id Monday\n"); break;
                case 1: printf("The day is Tuesday\n"); break;
                case 2: printf("The day is Wednesday\n"); break;
                case 3: printf("The day is Thursday\n"); break;
                case 4: printf("The day is Friday\n"); break;
                case 5: printf("The day is Saturday\n"); break;
                case 6: printf("The day is Sunday\n"); break;
                default: printf("Invalid input"); break;
        }
}

