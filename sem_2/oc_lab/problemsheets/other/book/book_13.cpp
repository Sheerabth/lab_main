#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

class Coin
{
    string sideUp;
    public:
        Coin();
        void toss();
        string getsideUp();
};


Coin::Coin()
{
    srand(time(0));
    int choice=rand()%2;
    if(choice)
        sideUp="heads";
    else
        sideUp="tails";
}

void Coin::toss()
{
    int choice=rand()%2;
    if(choice)
        sideUp="heads";
    else
        sideUp="tails";
}

string Coin::getsideUp()
{
    return sideUp;
}

int main()
{
    Coin quarter,dime,nickel;
    float dollar=0;
    while(dollar<1)
    {
        quarter.toss();
        dime.toss();
        nickel.toss();
        if(quarter.getsideUp()=="heads")
            dollar+=0.25;
        if(dime.getsideUp()=="heads")
            dollar+=0.1;
        if(nickel.getsideUp()=="heads")
            dollar+=0.05;
    }
    if(dollar==1)
        cout<<"You won the game\n";
    else
        cout<<"You lost the game\n";
}