#include<iostream>
#include<ios>
#include<limits>
#include<string>
using namespace std;

struct Element
{
    int atomicNumber;
    string name;
    string symbol;
    string Class;
    int atomicWeight;
    int electrons[7];
};

void read(Element *);
void display(Element);

int main()
{
    int i;
    Element ele[10];
    cout<<"Enter details of 10 elements:\n";
    for(i=0;i<10;i++)
    {
        cout<<"Enter the details of element "<<i+1<<endl;
        read(&ele[i]);
    }
    cout<<"The details of elements with atomic number greater than 11:\n";\
    for(i=0;i<10;i++)
    {
        if(ele[i].atomicNumber>11)
        {
            cout<<"Details of element "<<i+1<<endl;
            display(ele[i]);
        }
    }

}

void read(Element *e)
{
    int i;
    cout<<"Enter the atomic number: ";
    cin>>e->atomicNumber;
    cout<<"Enter the name of the element: ";
    cin.sync();
    getline(cin,e->name); 
    cout<<"Enter the symbol: ";
    cin.sync();
    getline(cin,e->symbol);
    cout<<"Enter the Class: ";
    cin.sync();
    getline(cin,e->Class);
    cout<<"Enter the atomic weight: ";
    cin>>e->atomicWeight;
    cout<<"Enter the number of electrons in each shell:\n";
    for(i=0;i<7;i++)
        cin>>e->electrons[i];
}

void display(Element e)
{
    int i;
    cout<<"The atomic number is: "<<e.atomicNumber<<endl;
    cout<<"The name of the element is "<<e.name<<endl;
    cout<<"The symbol of the element is "<<e.symbol<<endl;
    cout<<"The class of the element is "<<e.Class<<endl;
    cout<<"The atomic weight of the element is "<<e.atomicWeight<<endl;
    cout<<"The number of electrons in each shell are:\n";
    for(i=0;i<7;i++)
        cout<<e.electrons[i]<<"\t";
    cout<<endl;
}















