#include<stdio.h>
typedef struct
{
    int hour;
    int min;
    float sec;
}TIME_info;
void read(TIME_info *t)
{
    printf("Enter the hours: ");
    scanf("%d",&t->hour);
    printf("Enter the minutes: ");
    scanf("%d",&t->min);
    printf("Enter the seconds: ");
    scanf("%f",&t->sec);
}
void display(TIME_info t)
{
    printf("%d:%d:%.3f\n",t.hour,t.min,t.sec);
}
TIME_info convertTime1(double realTime)
{
    TIME_info t;
    t.hour=(int)(realTime/3600);
    realTime=realTime-t.hour*3600;
    t.min=(int)(realTime/60);
    realTime=realTime-t.min*60;
    t.sec=(float)realTime;
    return t;
}
double convertTime2(TIME_info t)
{
    return (double)(3600*t.hour+60*t.min+t.sec);
}
TIME_info addTimes(TIME_info one,TIME_info two)
{
    double d1,d2;
    d1=convertTime2(one);
    d2=convertTime2(two);
    return convertTime1(d1+d2);
}
TIME_info subTimes(TIME_info one,TIME_info two)
{
    double d1,d2;
    d1=convertTime2(one);
    d2=convertTime2(two);
    if(d1>d2)
        return convertTime1(d1-d2);
    else
        return convertTime1(d2-d1);
}
void main()
{
    TIME_info t1,t2;
    read(&t1);
    read(&t2);
    printf("The read time infos are:\n");
    display(t1);
    display(t2);
    printf("The sum of the times are:\n");
    display(addTimes(t1,t2));
    printf("The difference in the times are:\n");
    display(subTimes(t1,t2));
}