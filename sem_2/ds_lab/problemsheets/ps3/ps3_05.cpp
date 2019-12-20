#include<iostream>
using namespace std;
void main()
{
    int i,len;
    cout<<"Enter the length of the array: ";
    cin>>len;
    int *arr=new int[len]; 
    cout<<"Enter the elements of the sorted array:\n";
    for(i=0;i<len;i++)
        cin>>arr[i];
    if(arr[0]+arr[1]<1000)
        cout<<"There are two elements with sum less than 1000\n";
    else
        cout<<"Two elements with sum less than 1000 are not there\n";
}