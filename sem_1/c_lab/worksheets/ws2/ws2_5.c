#include<stdio.h>
#include<math.h>
void main()
{
        char c[4];
        float val;
        int a,b,n;
        printf("Enter the value\n");
        fgets(c,4,stdin);
        a=c[0]-'0';
        b=c[2]-'0';
        if(c[1]=='.')
        {
                val=pow((a+(b*0.1)),2);
                printf("The value is %f\n",val);
        }
        else printf("Invalid Input\n");
}
