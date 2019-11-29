#include<stdio.h>
#include<math.h>
void main()
{
        int n,num,k=0;
        printf("Enter an integer number: ");
        scanf("%d",&num);
        printf("\n");
        printf("The induvidual digits: ");
        n=num;
        for(int i=0;;i++)
        {
                if(num<=0) break;
                else
                {
                        num/=10;
                        k++;
                }
        }
        /*printf("%d\n",k);*/
        int a[k];
        for(int i=0;i<k;i++)
        {
                a[i]=n%10;
                n/=10;
        }
        for(int i=k-1;i>=0;i--) printf("%d  ",a[i]);
        printf("\n");
}
