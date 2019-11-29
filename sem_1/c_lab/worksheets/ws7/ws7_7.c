#include<stdio.h>
#include<stdio.h>
void main()
{
        char name1[100],name2[100];
        int score1,score2;
        printf("Enter the first person's name: ");
        scanf("%s",name1);
        printf("Enter the first person's score: ");
        scanf("%d",&score1);
        printf("Enter the second person's name: ");
        scanf("%s",name2);
        printf("Enter the second person's score: ");
        scanf("%d",&score2);
        if(score1>score2)
        {
                printf("%s won by %d\n",name1,score1-score2);
        }
        else if(score2>score1)
        {
                printf("%s won by %d\n",name2,score2-score1);
        }
        else printf("Its a tie\n");
}

