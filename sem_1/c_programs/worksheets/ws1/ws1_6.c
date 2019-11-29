#include<stdio.h>
void main()
{
        int oldr,newr;
        float bill;
        printf("Enter the value of old reading\n");
        scanf("%d",&oldr);
        printf("Enter the value of new reading\n");
        scanf("%d",&newr);
        bill=((newr-oldr)*7.13)+30.5;
        printf("The electricity bill is Rs.%f\n",bill);
}

