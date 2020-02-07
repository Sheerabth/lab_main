#include <iostream>
using namespace std;

template <class T>
class SinglyLinked;

template <class T>
class Node
{
    T data;
    Node<T> *next;
    friend Singly;

public:
    Node<T>() : data(0), next(NULL) {}
    Node<T>(T element) : data(element), next(NULL) {}
    Node<T>(const Node<T> &node) : data(node.data), next(node.next) {}
};

template <class T>
class SinglyLinked
{
    Node<T> *head;

public:
    SinglyLinked<T>() : head(NULL) {}
    void insBeg(Node<T>);
    bool insMid(Node<T>, Node<T>);
    bool insEnd(Node<T>);
    bool delBeg();
    bool delMid(Node<T>);
    bool delEnd();
    bool display();
};

template <class T>
void SinglyLinked<T>::insBeg(Node<T> node)
{
    Node<T> *ptr = new Node<T>(node);
    ptr->next = head;
    head = ptr;
}

template <class T>
bool SinglyLinked<T>::insMid(Node<T> element, Node<T> node)
{
    Node<T> *ptr = new Node<T>(node);
    Node<T> *t = head;
    bool found = false;
    if (head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    while (t != NULL)
    {
        if(t->data == element.data)
        {
            found = true;
            break;
        }
        t = t->next;
    }
    if(found)
    {
        ptr->next = t->next;
        t->next = ptr;
    }
    else
        cout << "Element not found\n";
    return 0;
}

template <class T>
bool SinglyLinked<T>::insEnd(Node<T> node)
{
    Node<T> *ptr=new Node<T>(node);
    Node<T> *t = head;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
        return 0;
    }
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = ptr;
    ptr->next = NULL;
    return 0;
}

template <class T>
bool SinglyLinked<T>::delBeg()
{
    Node<T> *t = head;
    if (head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    head = head->next;
    delete t;
    return 0;
}

template <class T>
bool SinglyLinked<T>::delMid(Node<T> element)
{
    bool found = false;
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    Node<T> *t=head;
    while(t->next != NULL)
    {
        if(t->data == element.data)
        {
            found = true;
            break;
        }
        t = t->next;
    }
    if(found)
    {
        delete t->next;
        t->next = NULL;
    }
    return 0;
}

template <class T>
bool SinglyLinked<T>::delEnd()
{
    if(head == NULL)
    {
        cout << "The linked list is empty\n";
        return 0;
    }
    Node<T> *t = head;
    if(t->next == NULL)
    {
        head = NULL;
        delete t;
        return 0;
    }
    while(t->next->next == NULL)
    {
        t = t->NULL;
    }
    delete t->next;
    t->next = NULL;
}

template <class T>
bool SinglyLinked<T>::display()
{
    if(head == NULL)
    {
        cout << "The linked list is empty\n";
        return 0;
    }
    Node<T> *t=head;
    cout << "The list contents are: \n";
    while(t != NULL)
    {
        cout << t->data << "\t";    
    }
    cout << endl;
}

int main()
{
}