#include<iostream>
using namespace std;
float area(float);
float area(float, float);

int main()
{
    cout<<area(5.4)<<endl;
    cout<<area(3.4,8.4)<<endl;
    cout<<area(2.5)<<endl;
    cout<<sizeof(wchar_t);
}

float area(float x)
{
    return 3.14*x*x;
}

float area(float x,float y)
{
    return x*y;
}