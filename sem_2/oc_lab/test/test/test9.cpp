#include<iostream>
using namespace std;
class Point
{
    int x_co,y_co;
    public:
        void set(int,int);
        bool isOrigin();
        void display();
        Point diff(Point);
};

void Point :: set(int x, int y)
{
    x_co=x;
    y_co=y;
}

bool Point :: isOrigin()
{
    if(x_co==0&&y_co==0)
        return true;
    else
        return false;
}

void Point :: display()
{
    cout<<"The X coordinate is "<<x_co<<endl;
    cout<<"The Y coordinate is "<<y_co<<endl;
}

Point Point :: diff(Point P2)
{   
    Point P;
    P.x_co=x_co-P2.x_co;
    P.y_co=y_co-P2.y_co;
    return P;
}

int main()
{
    Point P1,P2;
    P1.set(5,3);
    P2.set(2,1);
    Point P3=P1.diff(P2);
    P3.display();
}