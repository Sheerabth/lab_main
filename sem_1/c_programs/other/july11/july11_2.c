#include<stdio.h>
void main()
{
        int t,d,s,p,q;
        printf("\n enter the time");
        scanf("%d",&t);
        printf("\n enter the duration");
        scanf("%d",&d);
        s=t+d;
        p=s%100;
        q=s/100;
        if(p>60)
        {
                p=p-60;
                q=q+1;
        }
        if(q>=24)
        {
                q=q-24;
        }
        s=q*100+p;
        printf("\n the end time is %d",s);

}
