#include"stack.hpp"

int main()
{
    Stack<char> C;
    int size;
    char ch='1';
    cout<<"Enter the size of the stack: ";
    cin>>size;
    C.assignSize(size);
    cout<<"Enter the elements of the stack:\n";
    while(ch!='~')
    {
        cin>>ch;
        if(ch=='#')
            ch=C.pop();
        else
            C.push(ch);
    }
}