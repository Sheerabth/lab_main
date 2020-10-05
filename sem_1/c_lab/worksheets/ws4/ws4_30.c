#include<stdio.h>
void main()
{
	int in[4],p,n;
	char k,ch='y';
	printf("ID number\tBrand\n");
	printf("1\t\tPiels\n2\t\tCoors\n3\t\tBud\n4\t\tIron City\n");
	for(int i=0;i<4;i++)
	{
	k:	printf("Enter the inventory for ID number %d: ",i+1);
		scanf("%d",&in[i]);
		if(in[i]<0)
		{
			printf("Enter positive value\n");
			goto k;
		}
	}
	printf("Enter positive values for purchase and negative values for sales\n");
	while(ch=='y'||ch=='Y')
        {
	m:	printf("Enter the ID number to enter sales or purchase: ");
		scanf("%d",&n);
		if(!(n==1||n==2||n==3||n==4))
		{
			printf("Enter valid ID number\n");
			goto m;
		}
		--n;
	l:	printf("Enter the sales or purchase: ");
		scanf("%d",&p);
		in[n]+=p;
		if(in[n]<0)
		{
			printf("Enter valid details\n");
			in[n]-=p;
			goto l;
		}
		printf("Do you want to add further data(y/n)? ");
		scanf("%c%c",&k,&ch);
	}
	for(int i=0;i<4;i++)
	printf("The inventory for ID number %d contains %d in number\n",i+1,in[i]);
}

