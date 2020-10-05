#include<stdio.h>
void main()
{
        int k=1;
        while(k==1)
        {
                char *item;
                float price,ship;
                int n;;
                printf("Enter the name of the item\n");
                scanf("%s",item);
                printf("Enter the price in dollars\n");
                scanf("%f",&price);
                printf("Do you want overnight delivery?(yes=1,no=0)\n");
                scanf("%d",&n);
                if(price<10) ship+=2;
                else ship+=3;
                if(n==1) ship+=5;
                printf("%s\t\t%.2f\n",item,price);
                printf("shipping\t%.2f\t\n",ship);
                printf("Total\t\t%.2f\n",price+ship);
                printf("More item? (yes=1/no=0)\n");
                scanf("%d",&k);
        }
}
