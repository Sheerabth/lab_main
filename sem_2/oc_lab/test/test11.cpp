#include<iostream>
using namespace std;

class Point
{
    int x_co;
    int y_co;
    public:
        static int count;
        Point();
        Point(int, int );
        //Point(int, int=5 ); //Ambiguity
};

int Point::count=0;

Point::Point()
{
    x_co=0;
    y_co=0;
    count++;
}

Point::Point(int x_co, int y_co )
{
    this->x_co=x_co;
    this->y_co=y_co;
    count++;
}

int main()
{
    Point P1;
    Point P2(5,4);
    cout<<Point::count;
}