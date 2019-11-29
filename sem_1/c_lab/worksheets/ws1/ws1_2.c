#include <stdio.h>
#include <math.h>

int main()
{
        int ch=0;
        float rad,height,width,vol;
        while(!ch)
        {
                printf("\t\t#### Volume Calculation ####");
                printf("\n\nPress 1 for Cylinder");
                printf("\nPress 2 for Sphere");
                printf("\nPress 3 for Cone");
                printf("\nPress 4 for Pyramid");
                printf("\nEnter Your Choice  : ");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:
                                printf("\nEnter the Radius  : ");
                                scanf("%f",&rad);
                                printf("\nEnter the Height  : ");
                                scanf("%f",&height);
                                vol=height*rad*rad*3.1428;
                                printf("\n\nVolume of the cylinder is %f",$
                                break;
                        case 2:
                                printf("\nEnter the Radius : ");
                                scanf("%f",&rad);
                                vol=(4/3)*3.1428*rad*rad*rad;
                                printf("\nVolume of the Sphere : %f ",vol);
                                break;
                        case 3:
                                printf("\nEnter the Radius  : ");
                                scanf("%f",&rad);
                                printf("\nEnter the Height  : ");
                                scanf("%f",&height);
                                vol=height*rad*rad*3.1428*(1/3);
                                printf("\nVolume of the Cone is %f",vol);
                                break;
                        case 4:
                                printf("\nEnter The width : ");
                                scanf("%f",&width);
                                printf("\nEnter the length : ");
                                scanf("%f",&rad);
                                printf("Enter the height : ");
                                scanf("%f",&height);
                                vol=(1/3)*width*height*rad;
                                printf("\nVolume of the Pyramid is %f",vol$
                                break;#include <stdio.h>
#include <math.h>

int main()
{
        int ch=0;
        float rad,height,width,vol;
        while(!ch)
        {
                printf("\t\t#### Volume Calculation ####");
                printf("\n\nPress 1 for Cylinder");
                printf("\nPress 2 for Sphere");
                printf("\nPress 3 for Cone");
                printf("\nPress 4 for Pyramid");
                printf("\nEnter Your Choice  : ");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:
                                printf("\nEnter the Radius  : ");
                                scanf("%f",&rad);
                                printf("\nEnter the Height  : ");
                                scanf("%f",&height);
                                vol=height*rad*rad*3.1428;
                                printf("\n\nVolume of the cylinder is %f",$
                                break;
                        case 2:
                                printf("\nEnter the Radius : ");
                                scanf("%f",&rad);
                                vol=(4/3)*3.1428*rad*rad*rad;
                                printf("\nVolume of the Sphere : %f ",vol);
                                break;
                        case 3:
                                printf("\nEnter the Radius  : ");
                                scanf("%f",&rad);
                                printf("\nEnter the Height  : ");
                                scanf("%f",&height);
                                vol=height*rad*rad*3.1428*(1/3);
                                printf("\nVolume of the Cone is %f",vol);
                                break;
                        case 4:
                                printf("\nEnter The width : ");
                                scanf("%f",&width);
                                printf("\nEnter the length : ");
                                scanf("%f",&rad);
                                printf("Enter the height : ");
                                scanf("%f",&height);
                                vol=(1/3)*width*height*rad;
                                printf("\nVolume of the Pyramid is %f",vol$
                                break;
                        default:
                                printf("\n\nERROR! Please enter a valid ch$
                                ch=0;
                }
        }
        printf("\n")
        return 0;

}
