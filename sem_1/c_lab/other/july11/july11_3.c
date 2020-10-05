#include<stdio.h>
void main()
{
        char ch,ca;
        int t;
        float ir,fr,d;
        l1:printf("\n enter the customer name");
        scanf("%*c%c",&ch);
        printf("\n user type");
        scanf("%d",&t);
        if(t==1)
        printf("\n domestic");
        if(t==2)
        printf("\n office");
        if(t==3)
        printf("\n factory");
        printf("\n enter initial meter reading");
        scanf("%f",&ir);
        printf("\n enter current meter reading");
        scanf("%f",&fr);
        d=fr-ir;
        if(t==1)
        {
        if(d<=500)
        {
                ir=0.25;
        }
        else
        {
                ir=0.25+(ir-500)*0.37;
        }
        }
        if(t==2)
        {

        if(d<=1000)
        {
                ir=0.50;
        }
        else
        {
                ir=0.50+(ir-1000)*0.50;
        }
        }
        if(t==3)
        {
        if(d<=1500)
        {
                ir=0.65;
        }
        else
        {
                ir=0.65+(ir-1500)*0.65;
        }
        }
        printf("\n tamilnadu electricity board");
        printf("\n customer name:%c",ch);
        printf("\n initial reading:%f",ir);
        printf("\n current reading:%f",fr);
        printf("\n do you want to continue");
        scanf("%*c%c",&ca);
        if(ca=='y')
        {
                goto l1;
        }
        else if(ca=='n')
        {
                printf("\n you are done");
        }
}

