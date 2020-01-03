#include<iostream>
#include<ios>
#include<limits>
#include<string>
using namespace std;

struct Vehicle
{
    int regNo;
    string manName;
    int yearOfMake;
    string model;
    int type;
    string colour;
};

void read(Vehicle *);
void display(Vehicle);

int main()
{
    
}

void read(Vehicle *v)
{
    cout<<"Enter the registration number: ";
    cin>>v->regNo;
    cout<<"Enter the manufacturer name: ";
    cin.sync();
    getline(cin,v->manName);
    cout<<"Enter the year of manufacture: ";
    cin>>v->yearOfMake;
    cout<<"Enter the model: ";
    cin.sync();
    getline(cin,v->model);
    cout<<"Enter the type of vehicle (No. of wheels): ";
    cin>>v->type;
    cout<<"Enter the colour of the vehicle: ";
    cin.sync();
    getline(cin,v->colour);
}

void display(Vehicle v)
{
    cout<<"The registration number is: "<<v.regNo<<endl;
    cout<<"The manufacturer name is: "<<v.manName<<endl;
    cout<<"The year of manufacture is: "<<v.yearOfMake<<endl;
    cout<<"The model is: "<<v.model<<endl;
    cout<<"The type of vehicle is: "<<v.type<<" wheeler\n";
    cout<<"The colour of vehicle is: "<<v.colour<<endl;
}














