#include<stdio.h>
void main()
{
        char ch;
        int d;
        printf("Enter the letter\n");
        scanf("%c",&ch);
        if(ch=='a'||ch=='A'||ch=='b'||ch=='B'||ch=='c'||ch=='C') d=2;
        else if(ch=='d'||ch=='D'||ch=='e'||ch=='E'||ch=='f'||ch=='F') d=3;
        else if(ch=='g'||ch=='G'||ch=='h'||ch=='H'||ch=='i'||ch=='I') d=4;
        else if(ch=='j'||ch=='J'||ch=='k'||ch=='K'||ch=='l'||ch=='L') d=5;
        else if(ch=='m'||ch=='M'||ch=='n'||ch=='N'||ch=='o'||ch=='O') d=6;
        else if(ch=='p'||ch=='P'||ch=='r'||ch=='R'||ch=='s'||ch=='S') d=7;
        else if(ch=='t'||ch=='T'||ch=='u'||ch=='U'||ch=='v'||ch=='V') d=8;
        else if(ch=='w'||ch=='W'||ch=='x'||ch=='X'||ch=='y'||ch=='Y') d=9;
        else printf("Invalid Input\n");
        printf("The number is %d\n",d);
}
