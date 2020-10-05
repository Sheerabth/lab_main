#include<iostream>
using namespace std;
void fun(char='*',int=10);

int main()
{
    fun();
    fun('#');
    fun('$',5);
}

void fun(char ch,int x)
{
    for(int i=0;i<x;i++)
        cout<<ch<<"\t";
    cout<<endl;
}