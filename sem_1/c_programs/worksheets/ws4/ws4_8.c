#include<stdio.h>
float fact(int n)
{
        int t=1;
        for(int i=2;i<=n;i++)
        {
                t*=i;
        }
        return t;
}
void main()
{
	int n;
	float e=1,k=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		e+=1/fact(i);
		if(e-k<0.00001) break;
		else k=e;
	}
	printf("The euler's number is %f\n",e);
}
