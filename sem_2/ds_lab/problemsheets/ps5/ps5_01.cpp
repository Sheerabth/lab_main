#include <iostream>
using namespace std;

class Stack
{
    int top;
    int size;
    int *stack;

public:
    Stack();
    void assignSize(int);
    int push(int);
    int pop();
    int displayFromBottom();
    int displayFromTop();
    int count();
    ~Stack();
};

Stack::Stack()
{
    top = -1;
    stack = new int[0]();
}

Stack::~Stack()
{
    delete[] stack;
}

void Stack::assignSize(int size)
{
    delete[] stack;
    this->size = size;
    stack = new int[size]();
}

int Stack::push(int element)
{
    if (top == size - 1)
    {
        cout << "Stack is full\n";
        return 0;
    }
    top++;
    stack[top] = element;
    return 0;
}

int Stack::pop()
{
    int element;
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return 0;
    }
    element = stack[top];
    top--;
    return element;
}

int Stack::displayFromBottom()
{
    Stack S;
    int element;
    S.assignSize(size);
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return 0;
    }
    while (top != -1)
    {
        element = pop();
        S.push(element);
    }

    cout << "Displaying the stack from bottom:\n";

    for (int i = 0; i <= top; i++)
    {
        element = S.pop();
        cout << element << "\t";
        push(element);
    }
    cout << endl;
    return 0;
}

int Stack::displayFromTop()
{
    Stack S;
    int element;
    S.assignSize(size);
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return 0;
    }
    cout << "Displaying the stack from top:\n";
    while (top != -1)
    {
        element = pop();
        cout << element << "\t";
        S.push(element);
    }
    cout << endl;
    for (int i = 0; i <= top; i++)
    {
        element = S.pop();
        push(element);
    }
    return 0;
}

int Stack::count()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return 0;
    }
    cout << "The number of elements in the stack is " << top + 1 << endl;
}

int main()
{
    Stack S;
    int choice, size, element;
    char ch;
    cout << "Enter the size of the stack: ";
    cin >> size;
    S.assignSize(size);
    do
    {
        cout << "Available Operaitons:\n";
        cout << "1.Push\n";
        cout << "2.Pop\n";
        cout << "3.Display from botom\n";
        cout << "4.Display from top\n";
        cout << "5.Display from bottom\n";
        cout << "6.Display the number of elements in the stack\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to push: ";
            cin >> element;
            S.push(element);
            break;
        case 2:
            element = S.pop();
            cout << "The element popped out is " << element << endl;
            break;
        case 3:
            S.displayFromBottom();
            break;
        case 4:
            S.displayFromTop();
            break;
        case 5:
            S.count();
            break;
        default:
            cout << "Enter valid choice\n";
            break;
        }
        cout << "Do you want to continue?(y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}