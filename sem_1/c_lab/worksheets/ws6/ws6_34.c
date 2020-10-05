#include<stdio.h>
#include<string.h>
void main()
{
	int n,i,j;
	char a[100];
	printf("Enter the word: ");
	scanf("%s",a);
	n=strlen(a);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				a[i]=a[i]^a[j];
				a[j]=a[i]^a[j];
				a[i]=a[i]^a[j];
			}
		}
	}
	printf("The word in alphabetical order is %s\n",a);
}

