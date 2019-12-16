#include<chrono>
#include<iostream>
using namespace std;
using namespace std::chrono;

inline int fact(int x)
{
    int fac=1;
    for(int i=x;i>0;i--)
        fac*=i;
    return fac;
}

int main()
{
   auto start=high_resolution_clock::now();
    
    for(int i=0;i<10;i++)
        cout<<fact(5);

        auto stop=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<duration.count()<<endl;
}