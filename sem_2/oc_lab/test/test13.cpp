#include<iostream>

using namespace std;


class B
{
    static int count;
    public:
        B(){cout<<"B's constructor is called\n";
            count++;}
        static int retData(){ return count;}
};

int B::count=0;
int main()
{
    B b1,b2,b3;
    cout<<B::retData();
}