#include<stdio.h>
#include<string.h>
void main()
{
	int n,i,k,j;
	printf("Enter the number of entries: ");
	scanf("%d",&n);
	char str[n][20];
	int age[n];
	printf("Enter the entries:\n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the name of person %d: ",i+1);
		scanf("%*c%s",str[i]);
		printf("Enter the age of person %d: ",i+1);
		scanf("%d",&age[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(str[i],str[j])>0)
			{
				for(k=0;str[i][k]!='\0'&&str[j][k]!='\0';k++)
				{
					str[i][k]=str[i][k]^str[j][k];
					str[j][k]=str[i][k]^str[j][k];
					str[i][k]=str[i][k]^str[j][k];
				}
				age[i]=age[i]^age[j];
				age[j]=age[i]^age[j];
				age[i]=age[i]^age[j];
			}
		}
	}
	printf("The ordered entries are:\n");
	for(i=0;i<n;i++)
	{
		printf("Name of person %d: %s\n",i+1,str[i]);
		printf("Age of person %d: %d\n",i+1,age[i]);
	}
}
