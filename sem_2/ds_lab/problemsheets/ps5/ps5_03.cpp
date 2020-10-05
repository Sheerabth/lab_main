#include <iostream>
using namespace std;

template <class T>
class Doublestack
{
    int top1, top2;
    int size;
    T *stack;

public:
    Doublestack();
    ~Doublestack();
    void assignSize(int);
    int push(T, int);
    T pop(int);
    void high();
    void low();
    int displayStack1();
    int displayStack2();
};

template <class T>
Doublestack<T>::Doublestack()
{
    top1 = -1;
    top2 = size;
    stack = new T[0]();
}

template <class T>
Doublestack<T>::~Doublestack()
{
    delete[] stack;
}

template <class T>
void Doublestack<T>::assignSize(int size)
{
    delete[] stack;
    this->size = size;
    top2 = size;
    stack = new T[size]();
}

template <class T>
int Doublestack<T>::push(T element, int stackNo)
{
    if (top2 == top1 + 1)
    {
        cout << "Double stack is full\n";
        return -1;
    }
    if (stackNo == 1)
    {
        top1++;
        stack[top1] = element;
    }
    else if (stackNo == 2)
    {
        top2--;
        stack[top2] = element;
    }
    else
    {
        cout << "Invalid stack number\n";
        return -1;
    }
    return 0;
}

template <class T>
T Doublestack<T>::pop(int stackNo)
{
    T element;
    if (stackNo == 1)
    {
        if (top1 == -1)
        {
            cout << "First stack is empty\n";
            return -1;
        }
        element = stack[top1];
        top1--;
    }
    else if (stackNo == 2)
    {
        if (top2 == size)
        {
            cout << "Second stack is empty\n";
            return 0;
        }
        element = stack[top2];
        top2++;
    }
    else
    {
        cout << "Invalid stack number\n";
        return -1;
    }
    return element;
}

template <class T>
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
    int local_top = top1;
    while (top1 != -1)
    {
        element = pop(1);
        S.push(element, 1);
    }
    cout << "Displaying stack 1:\n";
    for (int i = 0; i <= local_top; i++)
    {
        element = S.pop(1);
        cout << element << "\t";
        push(element, 1);
    }
    cout<<endl;
    return 0;
}

template <class T>
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
    int local_top = top2;
    while (top2 != size)
    {
        element = pop(2);
        S.push(element, 2);
    }
    cout << "Displaying stack 2:\n";
    for (int i = local_top; i < size; i++)
    {
        element = S.pop(2);
        cout << element << "\t";
        push(element, 2);
    }
    cout<<endl;
    return 0;
}

template <class T>
void Doublestack<T>::high()
{
    if (top1 > size - 1 - top2)
    {
        cout << "Stack 1 is larger\n";
        displayStack1();
    }
    else if (top1 < size - 1 - top2)
    {
        cout << "Stack 2 is larger\n";
        displayStack2();
    }
    else
    {
        cout << "Both stacks are of equal size\n";
        displayStack1();
        displayStack2();
    }
}

template <class T>
void Doublestack<T>::low()
{
    if (top1 < size - 1 - top2)
    {
        cout << "Stack 1 is smaller\n";
        displayStack1();
    }
    else if (top1 > size - 1 - top2)
    {
        cout << "Stack 2 is smaller\n";
        displayStack2();
    }
    else
    {
        cout << "Both stacks are of equal size\n";
        displayStack1();
        displayStack2();
    }
}

int main()
{
    Doublestack<int> D;
    D.assignSize(10);
    D.push(3, 1);
    D.push(5, 1);
    D.push(2, 1);
    D.push(9, 2);
    D.push(7, 2);
    D.displayStack1();
    D.displayStack2();
    D.high();
    D.low();
}