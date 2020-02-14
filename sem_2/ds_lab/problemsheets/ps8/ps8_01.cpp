#include <iostream>
using namespace std;

template <class T>
class SinglyLinked;

template <class T>
class Node
{
    T data;
    Node<T> *next;
    friend SinglyLinked<T>;

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
    SinglyLinked<T>(SinglyLinked<T>&);
    SinglyLinked<T> operator +(SinglyLinked<T>);
    SinglyLinked<T> operator =(SinglyLinked<T>);

    int noOfElements();
    bool display();
    bool delMid(Node<T>);
    bool free();

    void append(Node<T>);
    T sum();
    bool sort();
    bool delEnd();
    bool delSecond();
    bool deleteNth(int);
    bool move(Node<T>,int);
    bool insertAfterNth(Node<T>,int);
    bool reverse(SinglyLinked<T>&);
    SinglyLinked<T>& combine(SinglyLinked<T>&);
    SinglyLinked<T>& union_(const SinglyLinked<T>&);
    SinglyLinked<T>& intersection(const SinglyLinked<T>&);
};

template <class T>
bool SinglyLinked<T>::insertAfterNth(Node<T> node, int pos)
{
    Node<T> *ptr = new Node<T>(node);
    Node<T> *t = head;
    bool found = false;
    int count = 0;
    if (head == NULL)
    {
        cout << "Linked list is empty\n";
        return -1;
    }
    while (t != NULL)
    {
        if(count == pos)
        {
            found = true;
            break;
        }
        t = t->next;
        count++;
    }
    if(found)
    {
        ptr->next = t->next;
        t->next = ptr;
    }
    else
    {
        cout << "Invalid position\n";
        return -1;
    }
    return 0;
}

template <class T>
void SinglyLinked<T>::append(Node<T> node)
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
        Node<T> *s = t->next;
        t->next = t->next->next;
        delete s;
    }
    else
        cout << "Element not found or cannot delete element \n";
    return 0;
}

template <class T>
bool SinglyLinked<T>::deleteNth(int pos)
{
    bool found = false;
    count = 1;
    if(head == NULL)
    {
        cout << "Linked list is empty \n";
        return -1;
    }
    Node<T> *t=head;
    while(t->next != NULL)
    {
        if(count == pos-1)
        {
            found = true;
            break;
        }
        t = t->next;
    }
    if(found)
    {
        Node<T> *s = t->next;
        t->next = t->next->next;
        delete s;
    }
    else if(count == 1)
    {
        delete t;
        head = NULL;
    }
    else
    {
        cout << "Element not found \n";
        return -1;
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
    while(t->next->next != NULL)
    {
        t = t->next;
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
        t = t->next;  
    }
    cout << endl;
}

int main()
{
    SinglyLinked <int>S;
    S.insBeg(5);
    S.insEnd(10);
    S.insMid(5,6);
    S.insMid(6,7);
    S.insMid(5,8);
    S.display();
    S.delEnd();
    S.display();
    S.delMid(6);
    S.display();
    S.delBeg();
    S.display();
    /* code */
}