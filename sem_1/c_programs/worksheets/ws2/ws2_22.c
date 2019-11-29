#include<stdio.h>
void main()
{
        int num,min;
        printf("Enter the number of integers\n");
        scanf("%d",&num);
        int a[num];
        printf("Enter the integers\n");
        for(int i=0;i<num;i++) scanf("%d",&a[i]);
        min=a[0];
        for(int i=1;i<num;i++) if(a[i]<min) min=a[i];
        printf("The minimum value is %d\n",min);
}
