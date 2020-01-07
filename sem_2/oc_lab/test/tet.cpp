#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class Point
{
    char *str;
    int len;
    public:
        Point();
        Point(Point &);
};

Point::Point()
{
    cout<<"Enter the length of the string: ";
    cin>>len;
    str=new char[len+1];
    cout<<"Enter the string: ";
    cin>>ws;
    cin.getline(str,len+1);
}

Point::Point(Point &P)
{
    len=P.len;
    str=new char[len+1];
    strcpy(str,P.str);
    cout<<str<<endl<<"copy constructor is called\n";
}

main()
{
    Point P1;
    Point P2=P1;
}