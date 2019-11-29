#include<stdio.h>
void binary(char ch)
{
        for(int i=sizeof(char)*8-1;i>=0;i--)
        {
                if(ch>>i&1) printf("1");
                else printf("0");
        }
        printf("\n");
}
void main()
{
	unsigned char x;
	int n;
	printf("Enter the charachter: ");
	scanf("%c",&x);
	binary(x);
	printf("Enter the number of times to rotate: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		if(x>>7) x=x<<1|1;
		else x=x<<1;
	}
	binary(x);
}
