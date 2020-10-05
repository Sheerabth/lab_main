#include<stdio.h>
void main()
{
        float pay;
        int hours;
        printf("\nEnter the no of working hours\n");
        scanf("%d",&hours);
        pay=390.75*hours;
        printf("\nYour pay is Rs.%f/ for working at %d hours\n",pay,hours);
}
