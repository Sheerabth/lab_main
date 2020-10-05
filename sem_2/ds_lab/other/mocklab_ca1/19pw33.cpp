#include<iostream>
#include<string>
using namespace std;

string infixTopostfix(string);
double evaluate(string);

class Stack
{
    int top,size;
    char *stack;
    public:
        Stack();
        char pop();
        int push(char);
        ~Stack();        
};

Stack::Stack()
{
    stack=new char[50]();
    top=-1;
    size=50;
}

Stack::~Stack()
{
    delete[] stack;
}

int Stack::push(char symbol)
{   
    if(top==size-1)
    {
        cout<<"Stack is full\n";
        return 0;
    }
    top++;
    stack[top]=symbol;
    return 0;
}

char Stack::pop()
{
    if(top==-1)
    {
        cout<<"Stack is empty\n";
        return 0;
    }
    char symbol=stack[top];
    top--;
    return symbol; 
}

int main()
{
    double value;
    string infixExp,postfixExp;
    cout<<"Enter the infix expression:\n";
    cin.sync();
    getline(cin,infixExp);
    postfixExp=infixTopostfix(infixExp);
    cout<<"The postfix expression is:\n";
    cout<<postfixExp<<endl;
    /*value=evaluate(postfixExp);
    cout<<"The value of the postfix expression is "<<value<<endl;*/
}

string infixTopostfix(string infixExp)
{
    string postfixExp="";
    int j=0;
    Stack S;
    int pre1=0,pre2=0;
    for(int i=0;i<infixExp.length();i++)
    {
        if(infixExp[i]=='(')
        {
            S.push(infixExp[i]);
        }
        else if(infixExp[i]=='*'||infixExp[i]=='/')
        {
            pre1=pre2;
            pre2=5;
            S.push(infixExp[i]);
        }
        else if(infixExp[i]=='+'||infixExp[i]=='-')
        {
            pre1=pre2;
            pre2=4;
            if(pre2<pre1)
            {
                char ch=S.pop();
                while(ch!='(')
                {
                    postfixExp.push_back(ch);
                    ch=S.pop();
                }
            }
            S.push(infixExp[i]);
        }
        else if((infixExp[i]=='>'||infixExp[i+1]=='<'||infixExp[i]=='=')&&infixExp[i+1]=='=')
        {
            pre1=pre2;
            pre2=3;
            if(pre2<pre1)
            {
                char ch= S.pop();
                while(ch!='(')
                {
                    postfixExp.push_back(ch);
                    ch=S.pop();
                }
            }
            S.push(infixExp[i]);
            S.push(infixExp[i+1]);
            i++;
        }
        else if(infixExp[i]=='>'||infixExp[i]=='<')
        {
            pre1=pre2;
            pre2=3;
            if(pre2<pre1)
            {
                char ch= S.pop();
                while(ch!='(')
                {
                    postfixExp.push_back(ch);
                    ch=S.pop();
                }
            }
            S.push(infixExp[i]);
        }
        else if(infixExp[i]==')')
        {
            char ch=S.pop();
            while(ch!='(')
            {
                postfixExp.push_back(ch);
                ch=S.pop();
            }
            pre2=0;
        }
        else
        {
            postfixExp.push_back(infixExp[i]);
        }
    }
    return postfixExp;
}