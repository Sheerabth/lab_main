#include<stdio.h>
void name1(int k)
{
        switch(k)
        {
                case 0: printf("ZERO");
                        break;
                case 1: printf("ONE");
                        break;
                case 2: printf("TWO");
                        break;
                case 3: printf("THREE");
                        break;
                case 4: printf("FOUR");
                        break;
                case 5: printf("FIVE");
                        break;
                case 6: printf("SIX");
                        break;
                case 7: printf("SEVEN");
                        break;
                case 8: printf("EIGHT");
                        break;
                case 9: printf("NINE");
                        break;
                case 10: printf("TEN");
                         break;
                case 11: printf("ELEVEN");
                         break;
                case 12: printf("TWELVE");
                         break;
                case 13: printf("THIRTEEN");
                         break;
                case 14: printf("FOURTEEN");
                         break;
                case 15: printf("FIFTEEN");
                         break;
                case 16: printf("SIXTEEN");
                         break;
                case 17: printf("SEVENTEEN");
                         break;
                case 18: printf("EIGHTEEN");
                         break;
                case 19: printf("NINETEEN");
                         break;
                case 20: printf("TWENTY ");
                         break;
                case 30: printf("THIRTY ");
                         break;
                case 40: printf("FORTY ");
                         break;
                case 50: printf("FIFTY ");
                         break;
                case 60: printf("SIXTY ");
                         break;
                case 70: printf("SEVENTY ");
                         break;
                case 80: printf("EIGHTY ");
                         break;
                case 90: printf("NINTY ");
                         break;
                case 100: printf("ONE HUNDRED ");
                          break;
        }
}
void name2(int p)
{
        switch(p)
        {
                case 1: printf("TEN ");
                         break;
		case 2: printf("TWENTY ");
                         break;
                case 3: printf("THIRTY ");
                         break;
                case 4: printf("FORTY ");
                         break;
                case 5: printf("FIFTY ");
                         break;
                case 6: printf("SIXTY ");
                         break;
                case 7: printf("SEVENTY ");
                         break;
                case 8: printf("EIGHTY ");
                         break;
                case 9: printf("NINTY ");
                         break;
	}
}

void main()
{
        float n,rem;
	int val,i=1;
	int a1,a2;
        printf("Enter the number\n");
        scanf("%f",&n);
	int num=(int)n;
	rem=n-num;
        while(1)
	{
		val=(int)rem;
		if(rem-val==0)
			break;
		else
		{
			rem*=10;
			i*=10;
		}
	}
	if(num%10==0||num<=20)
        {
                name1(num);
        }
        else
        {
                a1=num%10;
                a2=num/10;
                name2(a2);
                name1(a1);
        }
	printf(" and %d/%d\n",(int)rem,i);
}

