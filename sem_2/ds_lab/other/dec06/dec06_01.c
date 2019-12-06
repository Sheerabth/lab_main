#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,n,sum1=0,sum2;
    printf("Enter the number: ");
    scanf("%d",&n);
    int *a=(int *)malloc((n-1)*sizeof(int));
    printf("Enter the elements:\n");
    for(i=0;i<n-1;i++)
        scanf("%d",&a[i]);
    sum2=(n*(n+1))/2;
    for(i=0;i<n;i++)
        sum1+=a[i];
    printf("The missing number is %d\n",sum2-sum1);
}