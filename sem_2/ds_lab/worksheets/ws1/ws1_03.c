#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void main()
{
        int i,marks=0;
        char ch,ans[10]={'B','C','A','D','A','B','C','D','A','C'};
        printf("Enter the answers:\n");
        for(i=0;i<10;i++)
        {
                ch=getch();
                printf("%c\n",ch);
                ch=toupper(ch);
                if(ch==ans[i])
                        marks+=4;
                else
                        marks-=1;
        }
        printf("The total score of student is %d\n",marks);
}
