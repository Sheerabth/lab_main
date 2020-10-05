#include <stdio.h>

int main()
{
        int inp_sec,cp,min,hrs;
        printf("\t\t #### TIME CALCULATION ####");
        printf("\n\nEnter the value in Seconds : ");
        scanf("%d",&inp_sec);
        cp=inp_sec;
        hrs=inp_sec/3600;
        inp_sec=inp_sec%3600;
        min=inp_sec/60;
        inp_sec=inp_sec%60;
        printf("\n\n %d Seconds gives %d hours, %d Minutes and %d Seconds\$
        return 0;
}
