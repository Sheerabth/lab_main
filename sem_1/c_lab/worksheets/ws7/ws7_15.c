#include<stdio.h>
#include<math.h>
#include<string.h>
void main()
{
    long res=0;
    int i,j,k;
    char ch,colour[3][10],COLOR_CODES[10][7]={"black","brown","red","orange","yellow","green","blue","violet","gray","white"};
    do
    {
        printf("Enter the band colours:\n");
        for(i=0;i<3;i++)
        {
            printf("BAND%d: ",i+1);
            scanf("%s",colour[i]);
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<10;j++)
            {
                if(strcmp(colour[i],COLOR_CODES[j])==0)
                {
                    k=1;
                    if(i==0)
                        res+=j*10;
                    else if(i==1)
                        res+=j;
                    else if(i==2)
                        res*=pow(10,j);
                }
            }
            if(k==0)
            {
                printf("Enter valid colour\n");
                goto l;
            }
        }
        printf("The resistance is %ld ohms\n",res);
l:      printf("Do you want to decode another resistor?(y/n)");
        scanf("%*c%c",&ch);
    }while(ch=='y'||ch=='Y');
}