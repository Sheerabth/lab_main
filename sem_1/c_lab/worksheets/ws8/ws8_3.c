#include<stdio.h>
void main()
{
	int a=5;
	double b=10;
	char c='r';
	int *A=&a;
	double *B=&b;
	char *C=&c;
	printf("Address is %x\tvalue is %d\t\tsize is %lu\n",&a,a,sizeof(a));
	printf("Address is %x\tvalue is %f\tsize is %lu\n",&b,b,sizeof(b));
	printf("Address is %x\tvalue is %c\t\tsize is %lu\n",&c,c,sizeof(c));
	printf("Address is %x\tvalue is %x\tsize is %lu\n",&A,A,sizeof(A));
	printf("Address is %x\tvalue is %x\tsize is %lu\n",&B,B,sizeof(B));
	printf("Address is %x\tvalue is %x\tsize is %lu\n",&C,C,sizeof(C));
}
