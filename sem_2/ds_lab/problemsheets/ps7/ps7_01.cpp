#include<iostream>
using namespace std;

template <class T>
class SinglyLinked;

template <class T>
class Node{
    T data;
    Node* next;
    friend Singly;
    public:
        Node();
};

template <class T>
Node<T>::Node()
{
    next=NULL;
}

template <class T>
class SinglyLinked{
    Node<T> *head;
    public:
        SinglyLinked();
        void insBeg(Node<T>);
        int insMid(T,Node<T>);
        int insEnd(Node<T>);
        int delBeg();
        int delMid(T);
        int delEnd();
        int display();
};

template <class T>
SinglyLinked<T>::SinglyLinked()
{
    head=NULL;
}

template <class T>
void SinglyLinked<T>::insBeg(Node<T> node)
{   
    node->next=head;
    head=node;
}

template <class T>
int SinglyLinked<T>::insMid(T element,Node<T> node)
{
    Node<T> *t=head;
    if(head==NULL)
    {
        cout<<"Linked list is empty\n";
        return 0;
    }
    while(t->data!=element)
    {
        t=t->next;
    }
    node->next=t->next;
    t->next=node;
    return 0;
}

template <class T>
int SinglyLinked

int main()
{

}