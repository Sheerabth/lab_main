#include<stdio.h>
void main()
{
        int payph,hours;
        float pay;
        printf("Enter the pay per hour\n");
        scanf("%d",&payph);
        printf("Enter the no. of hours worked\n");
        scanf("%d",&hours);
        if(hours<40)
        {
        pay=hours*payph;
        }
        else
        {
        pay=(hours*payph)+((hours-40)*0.5*payph);
        }
        printf("The total pay for the worker is Rs.%f\n",pay);
}
