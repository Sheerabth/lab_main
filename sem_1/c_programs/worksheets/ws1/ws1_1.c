#include<stdio.h>
#include<math.h>
void main()

{
	float p,r,t,i,s,n,a;
	printf("Enter the principle amount: ");
	scanf("%f",&p);

	printf("Enter the rate of interest: ");
	scanf("%f",&r);

	printf("Enter the time duration: ");
	scanf("%f",&t);

	i=p*r*t;

	printf("The Simple Interest is : %f",i);

	s=p*(1+r*t);

	printf("The maturity value is : %f",s);


	a=p*pow(1+r,n);

	printf("The compunt interest is : %f",a);

}
