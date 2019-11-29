#include<stdio.h>
void main()
{
	int n,i,k,p=0;
l:	printf("Enter the integer: ");
	scanf("%d",&n);
	if(n<2)
	{
		printf("Enter valid input\n");
		goto l;
	}
	if(n&1) n=n&-2;
	else
	{
		for(i=0;i<32;i++) if((n>>i)&1) break;
		n=`n<<i;
		for(k=1;k<i;k++) p+=1<<k;
		n=n|p;
	}
	printf("Nearest lower multiple of 2 is %d\n",n); 
}

