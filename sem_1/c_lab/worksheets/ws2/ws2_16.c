#include<stdio.h>
void main()
{
        int m,n,s1,s2,h;
        printf("Enter the larger value\n");
        scanf("%d",&m);
        printf("Enter the smaller value\n");
        scanf("%d",&n);
        if(m==n) printf("The two numbers should be different\n");
        else if(m<n) printf("The first number should be larger\n");
        else
        {
                s1=(m*m)-(n*n);
                s2=(2*m*n);
                h=(m*m)+(n*n);
                printf("The pythogorean tripple is (%d,%d,%d)\n",s1,s2,h);
        }
}
