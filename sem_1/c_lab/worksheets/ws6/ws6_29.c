#include<stdio.h>
#include<time.h>
void main()
{
	int a[100];
	srand(time(0));
	for(i=0;i<100;i++) a[i]=rand();
	for(i=0;i<50;i++)
	{
		a[i]=a[i]^a[100-i];
		a[100-i]=a[i]^a[100-i];
		a[i]=a[i]^a[100-i];
	}
	printf("The reversed array is:\n");
	for(i=0;i<100;i++) printf("%d\t",a[i]);
}
