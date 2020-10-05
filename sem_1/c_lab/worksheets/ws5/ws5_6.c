#include<stdio.h>
void main()
{
	int n,num;
	char a,ch;
	do
	{
		printf("Enter any number: ");
		scanf("%d",&n);
		printf("ENTER YOUR CHOICE\n");
		printf("1.Get the right most bit\n");
		printf("2.Get the 3 right most bits\n");
		printf("3.Get the leftmost bit\n");
		printf("4.Get the 3 leftmost bits\n");
		printf("5.Remove rightmost bit\n");
		printf("6.Remove 3 rightmost bits\n");
		printf("7.Remove leftmost bit\n");
		printf("8.Remove 3 leftmost bits\n");
		printf("9.Get 4 rightmost bits of any input and remove the last bit\n");
		printf("10.Remove first bit of any input and add it to the right\n");
	l:	scanf("%d",&num);
		if(num<1||num>10)
		{
			printf("Enter valid input\n");
			goto l;
		}
		else
		{
			switch(num)
			{
				case 1: printf("%d\n",n&1);
					break;
				case 2: printf("%d\t%d\t%d\n",(n>>2)&1,(n>>1)&1,n&1);
					break;
				case 3: printf("%d\n",(n>>31)&1);
					break;
				case 4: printf("%d\t%d\t%d\n",(n>>31)&1,(n>>30)&1,(n>>29)&1);
					break;
				case 5: printf("%d\n",n^1);
                	                break;
                	        case 6: printf("%d\t%d\t%d\n",n^1,n^(1<<1),n^(1<<2));
                	                break;
                	        case 7: printf("%d\n",n^(1<<31));
                	                break;
                	        case 8: printf("%d\t%d\t%d\n",n^(1<<31),n^(1<<30),n^(1<<29));
                	                break;
				case 9: printf("The rightmost 4 bits:\t%d\t%d\t%d\t%d\n",(n>>3)&1,(n>>2)&1,(n>>1)&1,n&1);
                	                printf("The number after removing last bit %d\n",n^1);
					break;
				case 10: if((n>>31)&1) printf("%d\n",(n<<1)||1);
					 else printf("%d\n",(n<<1));
			}
		}
		printf("Do you want to continue?(y/n): ");
		scanf("%c%c",&a,&ch);
	}while(ch=='y'||ch=='Y');
}
