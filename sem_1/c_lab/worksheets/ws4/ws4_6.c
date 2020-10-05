#include<stdio.h>
void main()
{
	char t,c,a[100][100];
	int n;
	printf("Enter total number of players: ");
	scanf("%d",&n);
	int p[n],k[n],sum[n],hit[n];
	float avg[n]/*,sum[n],hit[n]*/;
	for(int i=0;i<n;i++)
	{
		k[i]=0;
		sum[i]=0;
		hit[i]=0;
		printf("Enter player number: ");
		scanf("%d",&p[i]);
		c='Y';
		int j=-1;
		while(c=='Y')
		{
			++j;
			printf("Enter batting record: ");
			scanf("%c%c",&t,&a[i][j]);
			k[i]++;
			if(a[i][j]=='H') ++hit[i];
			if(a[i][j]=='H'||a[i][j]=='O') ++sum[i];
			printf("Do you want to continue?[Y/N] ");
			scanf("%c%c",&t,&c);
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("Player %d's record: ",p[i]);
		for(int j=0;j<k[i];j++) printf("%c",a[i][j]);
		avg[i]=hit[i]/sum[i];
		printf("\nPlayer %d's batting average: %.2f\n",p[i],avg[i]);
	}
} 
