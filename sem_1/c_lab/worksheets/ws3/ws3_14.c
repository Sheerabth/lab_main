#include<stdio.h>
#include<math.h>
void main()
{
	int n,a[100],p=0,k=0,r;
	printf("Enter the integer: ");
	scanf("%d",&n);
	for(int i=0;;i++)
	{
		if(n==0) break;
		else
		{
			a[i]=n%10;
			n/=10;
			k++;
		}
	}
	r=k-1;
	for(int i=0;i<k;i++)
	{
		p+=a[i]*pow(10,r);
		--r;
	}
	printf("Inverse of number is %d\n",p);
	printf("Double of the inverse is %d\n",p*2);
}

