#include<stdio.h>
int stairs(int n)
{
    static int count=0;
    if(n==0)
        count++;
    else if(n>0)
    {
        stairs(n-1);
        stairs(n-2);
    }
    return count;  
}
void main()
{
    int n;
    printf("Enter the number of stairs: ");
    scanf("%d",&n);
    printf("The number of ways are %d\n",stairs(n));
}