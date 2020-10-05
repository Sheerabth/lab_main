#include <iostream>
using namespace std;

template <class T>
class Stack
{
    int top;
    int size;
    T *stack;

public:
    Stack();
    Stack(int);
    void push(T);
    T pop();
    void displayFromBottom();
    void displayFromTop();
    int count();
    ~Stack();
};

template <class T>
Stack<T>::Stack()
{
    top = -1;
    stack = new T[0]();
}

template <class T>
Stack<T>::~Stack()
{
    delete[] stack;
}

template <class T>
Stack<T>::Stack(int size)
{
    delete[] stack;
    this->size = size;
    stack = new T[size]();
}

template <class T>
void Stack<T>::push(T element)
{
    if (top == size - 1)
    {
        cout << "Stack is full\n";
        return -1;
    }
    top++;
    stack[top] = element;
}

template <class T>
T Stack<T>::pop()
{
    T element;
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return 0;
    }
    element = stack[top];
    top--;
    return element;
}

template <class T>
void Stack<T>::displayFromBottom()
{
    Stack<T> S;
    T element;
    S.assignSize(size);
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }
    int local_top = top;
    while (top != -1)
    {
        element = pop();
        S.push(element);
    }

    cout << "Displaying the stack from bottom:\n";

    for (int i = 0; i <= local_top; i++)
    {
        element = S.pop();
        cout << element << "\t";
        push(element);
    }
    cout << endl;
}

template <class T>
void Stack<T>::displayFromTop()
{
    Stack<T> S;
    T element;
    S.assignSize(size);
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }
    int local_top = top;
    cout << "Displaying the stack from top:\n";
    while (top != -1)
    {
        element = pop();
        cout << element << "\t";
        S.push(element);
    }
    cout << endl;
    for (int i = 0; i <= local_top; i++)
    {
        element = S.pop();
        push(element);
    }
}

template <class T>
int Stack<T>::count()
{
    if (top == -1)
        return 0;
    return top + 1;
}