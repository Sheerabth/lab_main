#include<iostream>
using namespace std;
inline float funCircleArea(float);

int main()
{
    float area,r;
    cout<<"Enter the radius: ";
    cin>>r;
    area=funCircleArea(r);
    cout<<"Area of the circle is "<<area<<endl;
    
}

float funCircleArea(float x)
{
    return 3.14*x*x;
}