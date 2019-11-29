#include<stdio.h>
void main()
{
        int pollno,odometer;
        float gram;
        printf("Enter the pollutant number\n");
        scanf("%d",&pollno);
        printf("Enter number of grams emitted per mile\n");
        scanf("%f",&gram);
        printf("Enter odometer reading\n");
        scanf("%d",&odometer);
        switch(pollno)
        {
                case 1: if(odometer<50000)
                        {
                                if(gram<3.4) printf("The emissions donot e$
                                else printf("The emissions exceed permitte$
                                break;
                        }
                        else
                        {
                                if(gram<4.2) printf("The emissions donot e$
                                else printf("The emissions exceed permitte$
                        }
                        break;
                case 2: if(odometer<50000)
                        {
                                if(gram<0.31) printf("The emissions donot $
                                else printf("The emissions exceed the perm$
                        }
                        else
                        {
                                if(gram<0.39) printf("The emissions donot $
                                else printf("The emissions exceed the perm$
                        }
                        break;
                case 3: if(odometer<50000)
                        {
                                if(gram<0.4) printf("The emissions donot e$
                                else printf("The emissions exceed the perm$
                        }
                        else
                        {
                                if(gram<0.5) printf("The emissions donot e$
                                else printf("The emissions exceed the perm$
                        }
                        break;
                case 4: if(odometer<50000)
	                {
                                if(gram<0.25) printf("The emissions donot $
                                else printf("The emissions exceed the perm$
                        }
                        else
                        {
                                if(gram<0.31) printf("The emissions donot $
                                else printf("The emissions exceed the perm$
                        }
                        break;
        }
}

