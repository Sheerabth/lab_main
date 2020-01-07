#include<iostream>
#include<math.h>
using namespace std;

template<class T>
class Power
{
    T x;
    int y;
    public:
        Power(T,int=0);
        T power();
};

template<class T>
Power<T>::Power(T x,int y)
{
    this->x=x;
    this->y=y;
}

template<class T>
T Power<T>::power()
{
    return pow(x,y);
}

int main()
{
    Power<int> P1(5),P2(6,2);
    Power<float> P3(4.3,3);
    cout<<P1.power()<<endl<<P2.power()<<endl<<P3.power()<<endl;
}