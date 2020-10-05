#include<stdio.h>
void main()
{
        int i;
        printf("Decimal\t\t\t\tOctal\t\t\t\tHexadecimal\n");
        for(i=1;i<=256;++i)
        {
                printf("%d\t\t\t\t%o\t\t\t\t%x\n",i,i,i);
        }
}
