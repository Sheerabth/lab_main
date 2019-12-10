#include<iostream>
using namespace std;
int main()
{
    int x,c_p=0,c_n=0,c_o=0,c_e=0,y,s_i=0,c_g=0,num,len,i,total=0;
    float avg;
    cout<<"Enter the number of elements: ";
    cin>>len;
    int *ar=new int[len];
    cout<<"Enter the elements of the array:\n";
    for(i=0;i<len;i++)
        cin>>ar[i];
    for(i=0;i<len;i++)
        total+=ar[i];
    float avg=(float)total/len;
    cout<<"The total is"<<total<<"\n";
    cout<<"The average is"<<avg<<"\n";
    cout<<"Enter the number: ";
    cin>>num;
    for(i=0;i<len;i++)
    {
        if(ar[i]>=num)
            c_g++;
    }
    cout<<c_g<<"numbers are greater than"<<num<<"\n";
    
}