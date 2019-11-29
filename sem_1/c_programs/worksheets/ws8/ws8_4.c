#include <stdio.h>
void foo1(int xval)
{
	int  x;
	x = xval;
	printf("Address of x is %x\n",&x);/* print the address and value of x here */
}
void foo2(int dummy)
{
	int  y;
	printf("Address of y is %x\n",&y);/* print the address and value of y here */
}
int main()
{
	foo1(7);
	foo2(11);
	return 0;
}

