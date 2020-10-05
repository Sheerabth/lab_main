#include<stdio.h>
void main()
{
        int j,m,a,m1,a1,ns,as,f;
        printf("Enter the date\n");
        scanf("%d",&j);
        printf("Enter the month\n");
        scanf("%d",&m);
        printf("Enter the year\n");
        scanf("%d",&a);
        if(m==1)
        {
                m1=13;
                a1=a-1;
        }
        else if(m==2)
        {
                m1=14;
                a1=a-1;
        }
        else
        {
                m1=m;
                a1=a;
        }
        as=a1/100;
        ns=a1-(as*100);
        f=j+ns+(ns/4)+(5*as)+(as/4)+((13*m1)/5)+1;
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
