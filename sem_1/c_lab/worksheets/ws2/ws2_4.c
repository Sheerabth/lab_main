#include<stdio.h>
#include<string.h>
void main()
{
        int num,d,s;
        char suite[100],den[100];
        printf("Enter the number\n");
        scanf("%d",&num);
        if(num==13||num==26||num==39||num==52)
        {
                s=(num/13)-1;
                d=13;
        }
        else
        {
                s=num/13;
                d=num%13;
        }
        if(s==0) strcpy(suite,"Club");
        else if(s==1) strcpy(suite,"Diamond");
        else if(s==2) strcpy(suite,"Heart");
        else if(s==3) strcpy(suite,"Spade");
        if(d==1) strcpy(den,"Ace");
        else if(d==11) strcpy(den,"Jack");
        else if(d==12) strcpy(den,"Queen");
        else if(d==13)  strcpy(den,"king");
        else printf("Invaid\n");
        if(d==1||d==11||d==12||d==13) printf("%s of %s\n",den,suite);
        else printf("%d of %s\n",d,suite);
}

