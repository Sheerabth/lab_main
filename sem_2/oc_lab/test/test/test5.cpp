#include<iostream>
using namespace std;
float area(float);
float area(float, float=2.0);

int main()
{
    cout<<area(5.4)<<endl;
    cout<<area(3.4,8.4)<<endl;
}

float area(float x)
{
    return 3.14*x*x;
}

float area(float x,float y)
{
    return x*y;
}