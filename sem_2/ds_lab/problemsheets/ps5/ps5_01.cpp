#include"stack.hpp"

int main()
{
    Stack<int> S;
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
        cout << "5.Display the number of elements in the stack\n";
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