#include<stdio.h>
void main()
{
        float bmi,wt,ht;
        printf("Enter your weight(in pounds)\n");
        scanf("%f",&wt);
        printf("Enter your height(in inches)\n");
        scanf("%f",&ht);
        bmi=(703*wt)/(ht*ht);
        if(bmi<18.5) printf("Under weight\n");
        else if(bmi>=18.5&&bmi<25) printf("Normal\n");
        else if(bmi>=25&&bmi<30) printf("Overweight\n");
        else printf("Obese\n");
}

