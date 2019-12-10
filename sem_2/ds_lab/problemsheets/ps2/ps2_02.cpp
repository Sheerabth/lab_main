#include<iostream>
using namespace std;


void main()
{
    int i,j,k,n,choice;
    char ch;
    cout<<"Enter the number of elements of the array\n";
    cin>>n;
    int *ar=new int[n];
    cout<<"Enter the elements of the array";
    for(i=0;i<n;i++)
        cin>>ar[i];
    do
    {
        cout<<"Select your choice\n";
        cout<<"1.Insert an element at the beginning\n";
        cout<<"2.Insert an element at the end\n";
        cout<<"3.Insert an element at some index\n";
        cout<<"4.Delete an element at some index\n";
        cin>>choice;
        if(choice==1)
            ib(ar,n);
        else if(choice==2)
            ie(ar,n);
        else if(choice==3)
            in(ar,n);
        else if(choice==4)
            del(ar,n);
        cout<<"The array after alteration is\n";
        for(i=0;i<n;i++)
            cout<<ar[i]<<"\n";
        cout<<"Do you want to continue?(y/n)";
        cin>>ch
    } while (ch=='y'||ch=='Y');
    
   
    
}