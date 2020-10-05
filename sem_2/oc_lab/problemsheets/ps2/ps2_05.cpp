#include<iostream>
using namespace std;

template<class T>
class Maximum
{
    T x,y,z;
    public:
        Maximum(T,T,T);
        T Max();
};


template<class T>
Maximum<T>::Maximum(T x,T y,T z)
{   
    this->x=x;
    this->y=y;
    this->z=z;
}

template<class T>
T Maximum<T>::Max()
{
    if(x>=y&&x>=z)
        return x;
    else if(y>=x&&y>=z)
        return y;
    else if(z>=x&&z>=y)
        return z;
    else
        return -1;
}

int main()
{
    Maximum<float> m(93.2,4.6,5.8);
    cout<<m.Max()<<endl;
}