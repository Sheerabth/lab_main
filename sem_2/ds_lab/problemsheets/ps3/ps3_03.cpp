#include<iostream>

using namespace std;

int main()
{
    int i,j,len;
    cout<<"Enter the number of elements of the array: ";
    cin>>len;
    int *arr=new int[len];
    cout<<"Enter the elements of the array:\n";
    for(i=0;i<len;i++)
        cin>>arr[i];
    for(i=0,j=0;i<len;i++)
    {
        if(arr[i]<0)
        {
            arr[i]=arr[i]^arr[j];
            arr[j]=arr[i]^arr[j];
            arr[i]=arr[i]^arr[j];
            j++;
        }
    }
    cout<<"The elements after sorting are:\n";
    for(i=0;i<len;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}
