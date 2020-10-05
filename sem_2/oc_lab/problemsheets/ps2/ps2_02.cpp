#include<iostream>
using namespace std;

int tripleByValue(int);
void tripleByReference(int &);

int main()
{
    int x;
    cout<<"Enter the value: ";
    cin>>x;
    cout<<"Call by value: "<<tripleByValue(x)<<endl;
    tripleByReference(x);
    cout<<"Call by refereance: "<<x<<endl;
    return 0;
}

int tripleByValue(int x)
{
    return 3*x;
}

void tripleByReference(int &x)
{
    x*=3;
}