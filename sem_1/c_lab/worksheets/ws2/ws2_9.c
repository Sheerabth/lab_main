#include<stdio.h>
void main()
{
	int k,no,newno,d[4],temp;
	printf("Enter 1 for encoding other for decoding: ");
	scanf("%d",&k);
	if(k==1)
	{
        	printf("Enter the four digit number to be encrypted: ");
        	scanf("%d",&no);
		for(int i=0;i<4;i++)
		{
			if(i==3) d[3]=no;
			else d[i]=no%10;
			d[i]+=7;
			d[i]%=10;
			no/=10;
		}
        	temp=d[0];
        	d[0]=d[2];
       		d[2]=temp;
       		temp=d[1];
        	d[1]=d[3];
        	d[3]=temp;
        	newno=d[3]*1000+d[2]*100+d[1]*10+d[0];
        	printf("The encrypted number is %d\n",newno);
	}
	else
	{
		printf("Enter the four digit number to be decrypted: ");
		scanf("%d",&no);
		for(int i=0;i<4;i++)
                {
                        if(i==3) d[3]=no;
                        else d[i]=no%10;
                        no/=10;
                }
		temp=d[0];
                d[0]=d[2];
                d[2]=temp;
                temp=d[1];
                d[1]=d[3];
                d[3]=temp;
		for(int i=0;i<4;i++)
		{
			if(d[i]>=0&&d[i]<=6) d[i]+=3;
			else d[i]-=7;
		}
		newno=d[3]*1000+d[2]*100+d[1]*10+d[0];
		printf("The decrypted number is %d\n",newno);
	}
}
