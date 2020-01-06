#include<iostream>
using namespace std;

int main()
{
    int i,j,len,pairs=0;
    cout<<"Enter the number of elements: ";
    cin>>len;
    if(len<1)
    {
        cout<<"Invalid number of elements\n";
        return 0;
    }
    int *ar=new int[len];
    cout<<"Enter the array elements:\n";
    for(i=0;i<len;i++)
        cin>>ar[i];
    cout<<"The pairs which have to be inverted are:\n";
    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(ar[i]>ar[j])
            {
                cout<<"("<<i+1<<","<<j+1<<")"<<endl;
                pairs++;
            }
        }
    }
    cout<<pairs<<" pairs were inverted\n";
}
