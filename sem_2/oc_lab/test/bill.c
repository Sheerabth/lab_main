#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
struct bill_items
{
    char item_name[20];
    int item_no;
    float unit_price;
};
struct bill
{
    struct bill_items *bk;
    float total_cost;
    char time[30];
    int num;
};
void read(struct bill_items *b,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter the bill details of item %d\n",i+1);
        printf("Enter the bill item: ");
        scanf("%*c%s",b[i].item_name);
        printf("Enter the number of items: ");
        scanf("%d",&b[i].item_no);
        printf("Enter the unit price(in Rs.): ");
        scanf("%f",&b[i].unit_price);
    }
}
void display(struct bill b)
{
    for(int i=0;i<b.num;i++)
    {
        printf("Item name %s\n",b.bk[i].item_name);
        printf("Number of items is %d\n",b.bk[i].item_no);
        printf("Unit price is %.2f\n",b.bk[i].unit_price);
    }
    printf("Total number of items is %d\n",b.num);
    printf("Time is %s\n",b.time);
    printf("The total cost is Rs.%.2f\n",b.total_cost);
}
float calculate(struct bill_items *b,int n)
{
    float cost=0;
    for(int i=0;i<n;i++)
        cost+=b[i].unit_price*b[i].item_no;
    return cost;    
}
void main()
{
    int n,i;
    printf("Enter the number of bill items: ");
    scanf("%d",&n);
    struct bill_items *b=(struct bill_items *)malloc(n*sizeof(struct bill_items));
    printf("Enter the bill details:\n");
    read(b,n);
    FILE *f,*f1,*f2;
    f=fopen("bill_items.txt","w");
    fwrite(b,sizeof(struct bill_items),n,f);
    fclose(f);
    struct bill k;
    f1=fopen("bill_items.txt","r");
    f2=fopen("bill.txt","w");
    fread(b,sizeof(struct bill_items),n,f1);
    k.bk=b;
    k.total_cost=calculate(b,n);
    time_t curtime;
    time(&curtime);
    strcpy(k.time,&curtime);
    k.num=n;
    fwrite(&k,sizeof(struct bill),1,f2);
    display(k);
    fclose(f1);
    fclose(f2);
}