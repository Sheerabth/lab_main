#include<stdio.h>
int count=0,a[100];
void read(FILE *f)
{
	int j,temp,tmp;
	printf("Enter the number of elements in file: ");
	scanf("%d",&temp);
	printf("Enter the elements of file\n");
	for(j=0;j<temp;j++)
	{
		scanf("%d",&tmp);
		putw(tmp,f);
	}
	rewind(f);
}
void assign(FILE *f1,FILE *f2)
{
	int temp,tmp;
	while(1)
	{
		tmp=getw(f1);
		if(tmp==-1)
			break;
		while(1)
		{
			temp=getw(f2);
			if(temp==-1)
				break;
			if(tmp==temp)
			{
				a[count++]=tmp;
				break;
			}
		}
		rewind(f2);
	}
	rewind(f1);
}
void main()
{
	int tmp,temp,j,k,l;
	FILE *f[3];
	f[0]=fopen("file1.dat","w+");
	f[1]=fopen("file2.dat","w+");
	f[2]=fopen("file3.dat","w+");
	for(j=0;j<3;j++)
	{
		printf("Enter the details of file%d\n",j+1);
		read(f[j]);
	}
	assign(f[0],f[1]);
	assign(f[0],f[2]);
	assign(f[1],f[2]);
	fclose(f[0]);
	fclose(f[1]);
	fclose(f[2]);
	for(j=0;j<count-1;j++)
	{
		for(k=j+1;k<count;k++)
		{
			if(a[j]==a[k])
			{
				for(l=k;l<count-1;l++)
				{
					a[l]=a[l+1];
				}
				k--;
				count--;
			}
		}
	}
	for(j=0;j<count-1;j++)
	{
		for(k=j+1;k<count;k++)
		{
			if(a[j]>a[k])
			{
				a[j]=a[j]^a[k];
				a[k]=a[j]^a[k];
				a[j]=a[j]^a[k];
			}
		}
	}
	printf("The voters list is:\n");
	for(j=0;j<count;j++)
	{
		printf("%d\n",a[j]);
	}
}
