#include<iostream>
using namespace std;

template <typename T>

void fibonacci(T x)
{
    T a=-1,b=1,c=0;
    cout<<"Fibonacci ";
    for(T i=0;i<x;i++)
    {
        c=a+b;
        cout<<c<<"\t";
        a=b;
        b=c;
    }
    cout<<endl;
}

template <typename L>

int main()
{
    L n;
    cout<<"Enter the number till which to generate fibonacci series: ";
    cin>>n;
}
