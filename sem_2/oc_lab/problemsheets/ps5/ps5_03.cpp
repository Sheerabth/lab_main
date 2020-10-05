#include<iostream>
using namespace std;

class MusicalComposition
{
    string title, composer;
    int year;
    public:
        MusicalComposition(string, string, int);
        void display();
};

class NationalAnthem: public MusicalComposition
{
    string name;
    public:
        NationalAnthem::NationalAnthem(string title, string composer, int yr, string name) :  MusicalComposition(title, composer, yr)
        {
            this->name = name;
        }
        void display();
};

MusicalComposition::MusicalComposition(string title, string composer, int yr)
{
    this->title = title;
    this->composer = composer;
    this->yr = yr;
}

MusicalComposition::display()
{
    
}