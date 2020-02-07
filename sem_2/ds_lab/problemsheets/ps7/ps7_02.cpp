#include <iostream>
using namespace std;

template <class T>
class DoublyLinked;

template <class T>
class Node{
    T data;
    Node *next;
    Node *prev; 
    friend DoublyLinked;
    public:
        Node<T>() : data(0), next(NULL), prev(NULL) {}
        Node<T>(T element) : data(element), next(NULL), prev(NULL) {}
        Node<T>(const Node &node) : data(node.data), next(node.next), prev(node.prev) {}
};

template <class T>
class DoublyLinked{
    Node *head;
    public:
        DoublyLinked<T>() : head(NULL) {} 
        bool insBeg(Node<T>);
        bool insMidBef(Node<T>, Node<T>);
        bool insMidAft(Node<T>, Node<T>);
        bool insEnd(Node<T>);
        bool delBeg();
        bool delMidBef(Node<T>);
        bool delMidAft(Node<T>);
        bool delEnd();
};

template <class T>
bool DoublyLinked<T>::insBeg(Node<T> node)
{
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    Node<T> *ptr = new Node<T>(node);
    head->prev = ptr;
    ptr->next = head;
    head = ptr;
    return 0;
}

template <class T>
bool DoublyLinked<T>::insMidBef(Node<T> element, Node<T> node)
{
    bool found = false;
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    Node<T> *ptr = new Node<T>(node);
    Node<T> *t = head;
    while(t != NULL)
    {
        if(t->data == element.data)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        ptr->prev = t->prev;
        ptr->next = t;
        t->prev->next = ptr;
        t->prev = ptr;
    }
    else
        cout << "Element not found\n";
    return 0;
}

template <class T>
bool DoublyLinked<T>::insMidAft(Node<T> element, Node<T> node)
{
    bool found = false;
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    Node<T> *ptr = new Node<T>(node);
    Node<T> *t = head;
    while(t != NULL)
    {
        if(t->data == element.data)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        ptr->next = t->next;
        ptr->prev = t;
        t->next->prev = ptr;
        t->next = ptr; 
    }
    else
        cout << "Element not found\n";
    return 0;
}