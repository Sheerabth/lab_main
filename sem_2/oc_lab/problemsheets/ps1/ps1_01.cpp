#include<iostream>
using namespace std;
struct set
{
    int size;
    int *p;
};

void read(struct set &s)
{
    cout<<"Enter the number of elements: ";
    cin>>s.size;
    cout<<"Enter the elements of the array:\n";
    s.p=new int[s.size];
    for(int i=0;i<s.size;i++)
        cin>>s.p[i];
}

struct set merge(struct set &x,struct set &y)
{
    struct set z;
    z.size=x.size+y.size;
    z.p=new int[z.size]

}
int main()
{
    struct set s1,s2,s3;
    cout<<"Enter the details of first array\n";
    read(s1);
    cout<<"Enter the details of second array\n";
    read(s2);
    s3=merge(s1,s2);
    display(s3);
}
