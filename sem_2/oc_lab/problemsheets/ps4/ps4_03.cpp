#include <iostream>
using namespace std;

class Meal
{
    string name;
    int calorie;
    Meal() { name = NULL; calorie = 0;}
    Meal(string name, int calorie) { this->name = name; this->calorie = calorie; }
    friend ostream& operator << (ostream& , Meal&);
    friend istream& operator >> (istream& , Meal&);
    Meal& operator + (const Meal&);
};

ostream& operator << (ostream &out, Meal &M)
{
    out << "The name of the meal is: " << M.name << endl;
    out << "The calorie count is: " << M.calorie << endl;
    return out;
}

istream& operator >> (istream &in, Meal &M)
{
    cin.sync();
    cout << "Enter the meal name: ";
    in >> M.name;
    cout << "Enter the calorie count: ";
    in >> M.calorie;
    return in;
}

Meal& operator + (const Meal &M)
{
    return { "Daily Total", calorie + M.calorie }; 
}

