#include<stdio.h>
void main()
{
        int v,t;
        float rate;
        printf("Enter the Volume to be infused\n");
        scanf("%d",&v);
        printf("Enter the minutes over which to infuse\n");
        scanf("%d",&t);
        rate=(v*60)/t;
        printf("VBTI: %d\n",v);
        printf("Rate: %f\n",rate);
}
