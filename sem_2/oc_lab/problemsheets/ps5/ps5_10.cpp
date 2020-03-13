#include<iostream>
using namespace std;

class Worker
{
    protected:
        string name;
        float salaryRate;
        int hours;
    public:
        Worker(){}
        virtual float computePay() = 0;
        friend istream& operator >>( istream &, Worker &);
        friend ostream& operator <<( ostream &, Worker &);
        virtual ~Worker(){} 
};

istream& operator >>( istream &in, Worker &W)
{
    cin.sync();
    in >> W.name;
    in >> W.salaryRate;
    in >> W.hours;
    return in;
}
ostream& operator <<( ostream &out, Worker &W)
{
    out << W.name << endl;
    out << W.salaryRate << endl;
    out << W.hours << endl;
    out << W.computePay() << endl;
    return out;
}

class HourlyWorker:public Worker
{
    public:
        HourlyWorker(){}
        float computePay();
        ~HourlyWorker(){}
};

class SalariedWorker:public Worker
{
    public:
        SalariedWorker(){}
        float computePay();
        ~SalariedWorker(){}
};

float HourlyWorker::computePay()
{
    if(hours <= 40)
        return hours*salaryRate;
    else
        return 40*salaryRate + (hours-40)*1.5*salaryRate;    
}

float SalariedWorker::computePay()
{
    return 40*salaryRate;
}

int main()
{
    SalariedWorker S;
    HourlyWorker H;
    Worker *W = &S;
    cin >> *W;
    cout << *W;
    W = &H;
    cin >> *W;
    cout << *W;
    return 0;
}
