#include<stdio.h>
#include<math.h>
void main()
{
        float wind_chill,temp,wind_speed;
        printf("Enter the temperature in farenheit\n");
        scanf("%f",&temp);
        printf("Enter the wind speed\n");
        scanf("%f",&wind_speed);
        wind_chill=35.74+(0.6215*temp)+(0.4275*temp-35.75)*(pow(wind_speed$
        printf("The wind chill is %f\n",wind_chill);
}
