#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Country
{
    string name;
    int population;
    float area;
    float populationDensity;
    public:
        void read();
        void calculatePopulationDesnsity();
        void display();
        int returnPopulation();
        float returnArea();
};

int largestArea(Country *,int);
int largestPopulation(Country *,int);
int largestPopulationDensity(Country *,int);

void Country::read()
{
    cout<<"Enter the name of the country: ";
    cin.sync();
    getline(cin,name);
    cout<<"Enter the population of the country: ";
    cin>>population;
    cout<<"Enter the area of the country: ";
    cin>>area;
}

void Country::calculatePopulationDesnsity()
{
    populationDensity=population/area;
}

void Country::display()
{
    cout<<"The name of the country is "<<name<<endl;
    cout<<"The population of the country is "<<population<<endl;
    cout<<"The area of the country is "<<area<<endl;
    cout<<"The populaiton density of the country is "<<populationDensity;
}

int main()
{
    int num;
    cout<<"Enter the number of countries: ";
    cin>>num;
    Country *C=new Country[num];
    cout<<"Enter the details of the countries\n";
    for(int i=0;i<num;i++)
    {
        cout<<"Enter the details of the country "<<i+1<<":\n";
        C[i].read();
        C[i].calculatePopulationDesnsity();
    }
    cout<<"The details of the country with the largest area is:\n";
    C[largestArea(C,num)].display();
    C[largestPopulation(C,num)].display();
    C[largestPopulationDensity(C,num)].display();
}

int largestArea(Country *C,int num)
{
    float maxArea=0;
    int count;
    for(int i=0;i<num;i++)
    {
        if(C[i].returnArea()>maxArea)
        {
            maxArea=C[i].returnArea();
            count=i;
        }
    }
    return count;
}

int largestPopulation(Country *C,int num)
{
    int maxPopulation=0;
    int count;
    for(int i=0;i<num;i++)
    {
        if(C[i].returnArea()>maxPopulation)
        {
            maxPopulation=C[i].returnArea();
            count=i;
        }
    }
    return count;
}

int 