#include<iostream>
using namespace std;

template <typename T>
void fibonacci(T t)
{
    T a=-1,b=1,c=0;
    for(T i=0;i<t;i++)
    {
        c=a+b;
        cout<<c<<"\t";
        a=b;
        b=c;
    }
    cout<<endl;
}

int main()
{
    fibonacci<int>(34);
    fibonacci<char>('F');
    fibonacci<float>(8.93);
    fibonacci<long>(10);
    fibonacci<double>(4.567);
}