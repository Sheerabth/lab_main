#include<iostream>
#include<stdlib.h>
using namespace std;

int ins(int *ar,int &len,int pos,int ele)
{
    if(pos<1||pos>len+1)
    {
        cout<<"Invalid position\n";
        return 0;
    }
    len++;
    ar=(int *)realloc(ar,len*sizeof(int));
    for(int i=len-1;i>=pos-1;i--)
        ar[i]=ar[i-1];
    ar[pos-1]=ele;
    return 0;
}

int del(int *ar,int &len,int pos)
{
    if(pos<1||pos>len)
    {
        cout<<"Invalid position\n";
        return 0;
    }
    if(!len)
    {
        cout<<"No element to delete\n";
        return 0;
    }
    for(int i=pos-1;i<len;i++)
        ar[i]=ar[i+1];
    len--;
    ar=(int *)realloc(ar,len*sizeof(int));
    return 0;
}

int main()
{
    int i,len,choice,pos,ele;
    char ch;
    cout<<"Enter the number of elements of the array: ";
    cin>>len;
    int *ar=new int[len];
    cout<<"Enter the elements of the array\n";
    for(int i=0;i<len;i++)
        cin>>ar[i];
    do
    {
    l:  cout<<"Select your choice\n";
        cout<<"1.Insert an element at some index\n";
        cout<<"2.Delete an element at some index\n";
        cout<<"3.Insert an element at the beiginning of the array\n";
        cout<<"4.Insert an element at the middle of the array\n";
        cout<<"5.Insert an element at the end of the array\n";
        cout<<"6.Delete an element at the beiginning of the array\n";
        cout<<"7.Delete an element at the middle of the array\n";
        cout<<"8.Delete an element at the end of the array\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the position to be inserted: ";
            cin>>pos;
            cout<<"Enter the element to be inserted: ";
            cin>>ele;
            ins(ar,len,pos,ele);
        }
        else if(choice==2)
        {
            cout<<"Enter the position to be deleted: ";
            cin>>pos;
            del(ar,len,pos);
        }
        else if(choice==3)
        {
            cout<<"Enter the element to be added in the beginning: ";
            cin>>ele;
            ins(ar,len,1,ele);
        }
        else if(choice==4)
        {
            cout<<"Enter the element to be added in the middle: ";
            cin>>ele;
            ins(ar,len,len/2+1,ele);
        }
        else if(choice==5)
        {
            cout<<"Enter the element to be added in the end: ";
            cin>>ele;
            ins(ar,len,len+1,ele);
        }
        else if(choice==6)
            del(ar,len,1);
        else if(choice==7)
            del(ar,len,len/2);
        else if(choice==8)
            del(ar,len,len);
        else
        {
            cout<<"Enter valid input\n";
            goto l;       
        }
        cout<<"The array after alteration is\n";
        for(i=0;i<len;i++)
            cout<<ar[i]<<"\t";
        cout<<"\n";
        cout<<"Do you want to continue?(y/n): ";
        cin>>ch;
    } while (ch=='y'||ch=='Y');
    return 0;
}