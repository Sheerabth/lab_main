#include<stdio.h>
void main()
{
        int k=1;
        while(k!=-1)
        {
                int a[5];
                printf("Enter 5 integers seperated by a space: ");
                scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
                int small=a[0];
                for(int i=1;i<5;i++)
                if(a[i]<small) small=a[i];
                printf("The smallest number among %d %d %d %d %d is %d",a[$
                printf("\n\n");
                printf("More data? -1 to stop, others to continue: ");
                scanf("%d",&k);
        }

}

