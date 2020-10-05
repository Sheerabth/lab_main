#include<stdio.h>
void main()
{
	int a,b,c;
	printf("Enter the three sides of the triangle\n");
	line:	scanf("%d%d%d",&a,&b,&c);
		if(a+b<=c||b+c<=a||c+a<=b)
		{
			printf("The entered sides cannot form a triangle\n");
			printf("Enter valid input\n");
			goto line;
		}
	else
	{
		if(a==b&&b==c&&c==a) printf("Given triangle is an equilateral\n");
		else if(a==b||b==c||c==a) printf("Given triangle is an isosceles\n");
		else printf("Given triangle is neither equilateral nor isosceles\n");
	}
}
