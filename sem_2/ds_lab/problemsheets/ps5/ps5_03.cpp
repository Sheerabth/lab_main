#include<iostream>
using namespace std;

template<class T>
class Doublestack
{
    int top1,top2;
    int size;
    T *stack;
    public:
        Doublestack();
        ~Doublestack();
        void assignSize(int);
        int push(T,int);
        T pop(int);
        void high();
        void low();
        int displayStack1();
        int displayStack2();
};

template<class T>
Doublestack<T>::Doublestack()
{
    top1=-1;
    top2=size;
    stack=new T[0]();    
}   

template<class T>
Doublestack<T>::~Doublestack()
{
    delete[] stack;
}

template<class T>
void Doublestack<T>::assignSize(int size)
{
    this->size=size;
}

template<class T>
int Doublestack<T>::push(T element,int stackNo)
{
    if(top2=top1+1)
    {
        cout<<"Double stack is full\n";
        return 0;        
    }
    if(stackNo==1)
    {
        top1++;
        stack[top1]=element;
    }
    else if(stackNo==2)
    {
        top2--;
        stack[top2]=element;
    }
    else
    {
        cout<<"Invalid stack number\n";
        return 0;
    }
}

template<class T>
T Doublestack<T>::pop(int stackNo)
{
    T element;
    if(stackNo==1)
    {
        if(top1==-1)
        {
            cout<<"First stack is empty\n";
            return 0;
        }
        element=stack[top1];
        top1--;
        return element;
    }
    else if(stackNo==2)
    {
        if(top2==size)
        {
            cout<<"Second stack is empty\n";
            return 0;
        }
        element=stack[top2];
        top2++;
        return element;
    }
}

template<class T>
int Doublestack<T>::displayStack1()
{
    Doublestack<T> S;
    T element;
    S.assignSize(size);
    if (top1 == -1)
    {
        cout << "Stack 1 is empty\n";
        return 0;
    }
    int local_top=top1;
    cout << "Displaying stack 1:\n";
    while (top1 != -1)
    {
        element = pop(1);
        cout << element << "\t";
        S.push(element,1);
    }
    cout << endl;
    for (int i = 0; i <= local_top; i++)
    {
        element = S.pop(1);
        push(element,1);
    }
    return 0;
}

template<class T>
int Doublestack<T>::displayStack2()
{
    Doublestack<T> S;
    T element;
    S.assignSize(size);
    if (top2 == size)
    {
        cout << "Stack 2 is empty\n";
        return 0;
    }
    int local_top=top2;
    cout << "Displaying stack 1:\n";
    while (top2 != size)
    {
        element = pop(2);
        cout << element << "\t";
        S.push(element,2);
    }
    cout << endl;
    for (int i = 0; i <= local_top; i++)
    {
        element = S.pop(2);
        push(element,2);
    }
    return 0;
}

template<class T>
void Doublestack<T>::high()
{
    if(top1>size-1-top2)
    {
        cout<<"Stack 1 is larger\n";
        displayStack1();
    }
    else if(top1<size-1-top2)
    {
        cout<<"Stack 2 is larger\n";
        displayStack2();
    }
    else
    {
        cout<<"Both stacks are of equal size\n";
        displayStack1();
        displayStack2();
    }
}

template<class T>
void Doublestack<T>::low()
{
    if(top1<size-1-top2)
    {
        cout<<"Stack 1 is smaller\n";
        displayStack1();
    }
    else if(top1>size-1-top2)
    {
        cout<<"Stack 2 is smaller\n";
        displayStack2();
    }
    else
    {
        cout<<"Both stacks are of equal size\n";
        displayStack1();
        displayStack2();
    }
}

int main()
{

}