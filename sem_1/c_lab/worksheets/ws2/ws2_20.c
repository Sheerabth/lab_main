#include<stdio.h>
void main()
{
        int num,sum=0;
        printf("Enter the number of integers to be summed\n");
        scanf("%d",&num);
        int a[num];
        printf("Enter the integers\n");
        for(int i=0;i<num;++i) scanf("%d",&a[i]);
        for(int i=0;i<num;++i) sum+=a[i];
        printf("The sum is %d\n",sum);
}
