#include<stdio.h>
void main()
{
        float m[100],w[100],lm,hw,k;
        int me=0,wo=0;
        printf("Enter the men and women score alternatively\n");
        for(int i=0;;i++)
        {
                if(i%2==0)
                {
                        scanf("%f",&m[++me]);
                        if(m[me]==0) break;
                }
                else scanf("%f",&w[++wo]);
        }
        lm=m[1];
        hw=w[1];
        for(int i=1;i<=wo;i++)
        {
                if(m[i]<lm) lm=m[i];
                if(w[i]>hw) hw=w[i];
        }
        printf("Lowest men's: %f\n",lm);
        printf("Highest women's: %f\n",hw);
}

