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
    Coin C;
    short int upTime=0,downTime=0;
    cout<<"The side facing up initially: "<<C.getsideUp()<<endl;
    for(int i=0;i<20;i++)
    {
        C.toss();
        cout<<"The side facing up after toss "<<i+1<<" is: "<<C.getsideUp()<<endl;
        if(C.getsideUp()=="heads")
            upTime++;
        else
            downTime++;
    }
    cout<<"The number of times it shows heads facing up: "<<upTime<<endl;
    cout<<"The number of times it shows tails facing up: "<<downTime<<endl;
}