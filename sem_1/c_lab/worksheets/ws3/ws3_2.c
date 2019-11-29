#include<stdio.h>
#include<math.h>
void main()
{
        float v,wci,t;
        printf("Enter the wind speed in miles per hour\n");
        scanf("%f",&v);
        printf("Enter the temperature in farenheit\n");
        scanf("%f",&t);
        if(v>=0&&v<=4) wci=t;
        else if(v>=45) wci=1.6*t-55;
        else wci=91.4+(91.4-t)*(0.0203*v-0.304*sqrt(v)-0.474);
        printf("The wind chill index is %f\n",wci);
}
