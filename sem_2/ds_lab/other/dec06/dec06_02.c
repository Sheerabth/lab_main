#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,sum1,sum2=0;
    printf("Enter the number: ");
    scanf("%d",&n);
    int *a=(int *)malloc((n+1)*sizeof(int));
    printf("Enter the elements:\n");
    for(i=0;i<n+1;i++)
        scanf("%d",&a[i]);
    sum1=(n*(n+1))/2;
    for(i=0;i<n+1;i++)
        sum2+=a[i];
    printf("The number that has been repeated is %d\n",sum2-sum1);
}