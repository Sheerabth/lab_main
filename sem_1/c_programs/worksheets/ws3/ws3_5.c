#include<stdio.h>
void main()
{
        int k=1;
        while(k!=-1)
        {
                int num,r,sum=0;
                printf("Enter an integer: ");
                scanf("%d",&num);
                printf("\n");
                printf("After operation:\n");
                printf("remainder\tnum\n");
                printf("---------\t---\n");
                for(int i=0;;i++)
                {
                        if(num<=0) break;
                        else
                        {
                                r=num%10;
                                sum+=r;
                                printf("%d\t\t%d\n",r,num/=10);
                        }
                }
        printf("The sum of digits is %d\n",sum);
        printf("More? -1 to stop, other to continue: ");
        scanf("%d",&k);
        }
}

