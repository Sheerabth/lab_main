#include<stdio.h>
void main()
{
        char grade;
        int quality_Points;
        printf("Enter the grade\n");
        scanf("%c",&grade);
        if(grade=='D'||grade=='d') quality_Points=1;
        else if(grade=='C'||grade=='c') quality_Points=2;
        else if(grade=='B'||grade=='b') quality_Points=3;
        else if(grade=='A'||grade=='a') quality_Points=4;
        else quality_Points=0;
        printf("The quality Points is %d\n",quality_Points);
}
