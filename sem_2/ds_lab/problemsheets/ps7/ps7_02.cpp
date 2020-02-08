#include <iostream>
using namespace std;

template <class T>
class DoublyLinked;

template <class T>
class Node{
    T data;
    Node<T> *next;
    Node<T> *prev; 
    friend DoublyLinked;
    public:
        Node<T>() : data(0), next(NULL), prev(NULL) {}
        Node<T>(T element) : data(element), next(NULL), prev(NULL) {}
        Node<T>(const Node<T> &node) : data(node.data), next(node.next), prev(node.prev) {}
};

template <class T>
class DoublyLinked{
    Node<T> *head;
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
        bool display();
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
        t = t->next;
    }
    if(found)
    {
        ptr->prev = t->prev;
        ptr->next = t;
        if(t == head)
            head = head->prev;
        else
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
        t = t->next;
    }
    if(found)
    {
        ptr->next = t->next;
        ptr->prev = t;
        if(t->next != NULL)
            t->next->prev = ptr;
        t->next = ptr; 
    }
    else
        cout << "Element not found\n";
    return 0;
}

template <class T>
bool DoublyLinked<T>::insEnd(Node<T> node)
{
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    Node<T> *ptr = new Node<T>(node);
    Node *t = head;
    while(t != NULL)
    {
        t = t->next;
    }
    t->next = ptr;
    ptr->prev = t;
    return 0;
}

template <class T>
bool DoublyLinked<T>::delBeg()
{
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    head = head->next;
    delete head->prev;
    head->prev = NULL;
    return 0;
}

template <class T>
bool DoublyLinked<T>::delMidBef(Node<T> element)
{
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    bool found = false;
    Node<T> *t = head;
    while(t != NULL)
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
        if(t == head)
        {
            cout << "Cannot delete element\n";
            return 0;
        }
        if(t->prev == head)
            head = head->next;
        else
            t->prev->prev->next = t;
        Node<T> *s = t->prev;
        t->prev = t->prev->prev;
        delete s;
    }
    else
        cout << "Element not found\n";
    return 0;
}

template <class T>
bool DoublyLinked<T>::delMidAft(Node<T> element)
{
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    bool found = false;
    Node<T> *t = head;
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
        if(t->next->next != NULL) 
            t->next->next->prev = t;
        Node<T> *s = t->next;
        t->next = t->next->next;
        delete s;
    }
    else
        cout << "Element not found or cannot be deleted\n";
    return 0;
}

template <class T>
bool DoublyLinked<T>::delEnd()
{
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    Node<T> *t = head;
    while(t->next != NULL)
    {
        t = t->next;
    }
    t->prev->next = NULL;
    delete t;
    return 0;
}

template <class T>
bool DoublyLinked<T>::display()
{
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    Node<T> *t = head;
    cout << "The contents of linked list are:\n";
    while(t != NULL)
    {
        cout << t->data << "\t";
        t = t->next;
    }
    cout << endl;
    return 0;
}

int main()
{
    /* code */
}