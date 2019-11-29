#include<stdio.h>
void main()
{
	int n,i,j,k=0;
	printf("Entert the number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if(a[i]>a[j])
                        {
                                a[i]+=a[j];
                                a[j]=a[i]-a[j];
                                a[i]=a[i]-a[j];
                        }
                }
        }
	/*for(i=0;i<n;i++) printf("%d\n",a[i]);*/
	for(i=0;i<n;i++)
	if(a[i]==1) k=1;
	if(k==1)
	{
		for(i=0;i<n;i++)
		if(a[i]>0&&(a[i]+1!=a[i+1])) break;
		printf("The integer is %d\n",a[i]+1);
	}
	else printf("The integer is 1\n");

}
