#include<iostream>
using namespace std;
class Rectangle
{
    private:
        float len,bre;
    public:
        float area();
        float perimeter();
        float getLen();
        float getBre();
        void setAtt();
};

void Rectangle::setAtt()
{
    cout<<"Enter the length: ";
    cin>>len;
    cout<<"Enter the breadth: ";
    cin>>bre;
} 

float Rectangle::getLen()
{
    return len;
}

float Rectangle::getBre()
{
    return bre;
}

float Rectangle::perimeter()
{
    return 2*(len+bre);
}

float Rectangle::area()
{
    return len*bre;
}

int main()
{
    Rectangle R1,R2;
    R1.setAtt();
    cout<<"The area is: "<<R1.area()<<endl;
    cout<<"The perimeter is: "<<R1.perimeter()<<endl;
}























