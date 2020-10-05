#include<stdio.h>
void main()
{
        float n;
        printf("Enter the Ritcher Scale Number\n");
        scanf("%d",&n);
        if(n<5) printf("Little or no damage\n");
        else if(n>=5&&n<5.5) printf("Some damage\n");
        else if(n>=5.5&&n<6.5) printf("Serious damage: walls may crack or $
        else if(n>=6.5&&n<7.5) printf("Disaster: houses and buildings may $
        else printf("Catastrophe: most buildings destroyed\n");
}

