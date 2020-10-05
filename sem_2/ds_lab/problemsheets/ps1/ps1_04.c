#include<stdio.h>
void main()
{
        int i,n,temp;
        printf("Enter the number of elements: ");
        scanf("%d",&n);
        int a1[n],a2[n],a3[n];
        printf("Enter the elements of first array:\n");
        for(i=0;i<n;i++)
                scanf("%d",&a1[i]);
        printf("Enter the elements of second array\n");
        for(i=0;i<n;i++)
                scanf("%d",&a2[i]);
        for(i=0;i<n;i++)
                a3[i]=a1[i]+a2[i];
        printf("The sum of both the arrays are\n");
        for(i=0;i<n;i++)
                printf("%d\t",a3[i]);
        printf("\n");
        int a4[n];
        for(i=0;i<n;i++)
                a4[i]=a1[i];
        printf("The contents of the fourth array are\n");
        for(i=0;i<n;i++)
                printf("%d\t",a4[i]);
        printf("\n");
        int a5[2*n];
        for(i=0;i<n;i++)
                a5[i]=a1[i];
        for(i=0;i<n;i++)
                a5[i+n]=a2[i];
        printf("The contents of the fifth array are\n");
        for(i=0;i<n*2;i++)
                printf("%d\t",a5[i]);
        printf("\n");
        for(i=0;i<n/2;i++)
        {
                a3[i]=a3[i]^a3[n-i-1];
 		a3[n-i-1]=a3[i]^a3[n-i-1];
                a3[i]=a3[i]^a3[n-i-1];
        }
        printf("The contents of the third array after reversing are\n");
        for(i=0;i<n;i++)
                printf("%d\t",a3[i]);
        printf("\n");
}
