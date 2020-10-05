#include<iostream>

using namespace std;

template <class T>
class Pstack
{
    T *stack;
    int top,size;
    T pop();
    public:
        Pstack();
        void assignSize(int);
        int push(T);
        T pPop(int);
        int getCount();
        ~Pstack();
};

template <class T>
Pstack<T>::Pstack()
{
    top=-1;
    size=0;
    stack=new T[0]();
}

template <class T>
void Pstack<T>::assignSize(int size)
{
    this->size=size;
    top=size;
    stack=new T[size]();
}


template <class T>
int Pstack<T>::push(T element)
{
    if(top==size-1)
    {
        cout<<"Stack is full\n";
        return -1;
    }
    top=top+1;
    stack[top]=element;
    return 0;
}

template <class T>
T Pstack<T>::pop()
{
    if(top==-1)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    T element=stack[top];
    top=top-1;
    return element;
}

template <class T>
T Pstack<T>::pPop(int pos)
{
    T temp_element,element;
    Pstack Temp;
    Temp.assignSize(size);
    for(int i=0;i<size-pos+1;i++)
    {
        temp_element=pop();
        Temp.push(temp_element);
    }
    element=pop();
    for(int i=0;i<size-pos+1;i++)
    {
        temp_element=Temp.pop();
        push(temp_element);
    }
    return element;
}

template <class T>
int Pstack<T>::getCount()
{
    return top+1;
}

template <class T>
Pstack<T>::~Pstack()
{
    delete[] stack;
}

int main()
{
    Pstack<int> P;
    P.assignSize(10);
    P.push(3);
    P.push(4);
    P.push(7);
    P.push(9);
    P.pPop(2);
}