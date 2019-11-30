#include<stdio.h>
void main()
{
    int win,i,j,vote[5][4],can[4]={0},total=0;
    float per,max=0;
    for(i=0;i<4;i++)
    {
        printf("Enter the votes of candidate %c in 5 precinct:\n",i+65);
        for(j=0;j<5;j++)
            scanf("%d",&vote[j][i]);
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            can[i]+=vote[j][i];
            total+=vote[j][i];
        }
        printf("Total number of votes by candidate %c is %.2d\n",i+65,can[i]);
    }
    for(i=0;i<4;i++)
    {
        per=(float)(can[i]*100)/total;
        printf("The percentage of votes recieved by candidate %c is %f%%\n",i+65,per);
        if(per>max)
        {
            max=per;
            win=i;
        }
    }
    printf("The winner is candidate %c\n",win+65);
}