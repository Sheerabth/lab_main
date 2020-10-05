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
    SinglyLinked<T>(const SinglyLinked<T> &); //
    SinglyLinked<T>& operator=(const SinglyLinked<T> &);  //

    int noOfElements(); //
    bool display(); //
    void free();    //

    void append(Node<T>);   //
    T sumOfElements();  //
    bool sort();    //
    bool delEnd();  //
    bool reverse(); //
    bool delSecond();   //
    bool delEveryNth(int);  //
    bool deleteNth(int);    //
    bool move(int, int);    //
    bool insertAfterNth(Node<T>, int);  //
    bool concatenate(SinglyLinked<T> &);    //
    SinglyLinked<T> &combine(SinglyLinked<T> &);
    SinglyLinked<T> &union_(const SinglyLinked<T> &);
    SinglyLinked<T> &intersection(const SinglyLinked<T> &);
};

template <class T>
SinglyLinked<T>::SinglyLinked<T>(const SinglyLinked<T> &S)
{
    if (S.head == NULL)
        head = NULL;
    else
    {
        Node<T> *t1 = S.head;
        Node<T> *t2 = head;
        while (t1 != NULL)
        {
            Node<T> *temp = new Node<T>();
            temp->data = t1->data;
            if (t2 == head)
                head = temp;
            else
                t2->next = temp;
            t2 = temp;
            t1 = t1->next;
        }
    }
}

template <class T>
SinglyLinked<T>& SinglyLinked<T>::operator=(const SinglyLinked<T> &S)
{
    free();
    Node<T> *t1 = S.head;
    Node<T> *t2 = head;
    while (t1 != NULL)
    {
        Node<T> *temp = new Node<T>();
        temp->data = t1->data;
        if (t2 == head)
            head = temp;
        else
            t2->next = temp;
        t2 = temp;
        t1 = t1->next;
    }
    return *this;
}

template <class T>
int SinglyLinked<T>::noOfElements()
{
    int count = 0;
    Node<T> *t = head;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}

template <class T>
bool SinglyLinked<T>::display()
{
    if (head == NULL)
    {
        cout << "The linked list is empty \n";
        return -1;
    }
    Node<T> *t = head;
    cout << "The elements of the linked list are: \n";
    while (t != NULL)
    {
        cout << t->data << "\t";
        t = t->next;
    }
    cout << endl;
    return 0;
}

template <class T>
void SinglyLinked<T>::free()
{
    Node<T> *t = head;
    while (t != NULL)
    {
        Node<T> *s = t;
        delete s;
        t = t->next;
    }
    head = NULL;
}

template <class T>
void SinglyLinked<T>::append(Node<T> node)
{
    Node<T> *ptr = new Node<T>(node);
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
T SinglyLinked<T>::sumOfElements()
{
    T sum = 0;
    if (head == NULL)
        cout << "The list is empty \n";
    else
    {
        Node<T> *t = head;
        while (t != NULL)
        {
            sum += t->data;
            t = t->next;
        }
    }
    return sum;
}

template <class T>
bool SinglyLinked<T>::sort()
{
    if(head == NULL)
    {
        cout << "List is empty \n";
        return -1;
    }
    T temp;
    Node *t = head;
    for(Node<T> *i = head; i->next != NULL; i = i->next)
    {
        for(Node<T> *j = i->next; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

template <class T>
bool SinglyLinked<T>::delEnd()
{
    if (head == NULL)
    {
        cout << "The linked list is empty\n";
        return 0;
    }
    Node<T> *t = head;
    if (t->next == NULL)
    {
        head = NULL;
        delete t;
        return 0;
    }
    while (t->next->next != NULL)
    {
        t = t->next;
    }
    delete t->next;
    t->next = NULL;
}

template <class T>
bool SinglyLinked<T>::reverse()
{
    
    if(head == NULL)
    {
        cout << "List is empty \n";
        return -1;
    }
    else if(head->next == NULL)
    {
        cout << "Single element. No effect due to reversal \n";
        return 0;
    }
    Node<T> *t1 = head;
    Node<T> *t2 = t1->next;
    Node<T> *t3; 
    t1->next = NULL;
    while(t3 != NULL)
    {
        t3 = t2->next;
        t2->next = t1;
        t1 = t2;
        t2 = t3;
    }
    return 0;
}

template <class T>
bool SinglyLinked<T>::delSecond()
{
    delEveryNth(2);
}

template <class T>
bool SinglyLinked<T>::delEveryNth(int pos)
{
    if(head == NULL)
    {
        cout << "List is empty \n";
        return -1;
    }
    else if(head->next == NULL && pos == 1)
    {
        delete head;
        head = NULL;
        return 0;
    }
    else if(pos == 1)
    {
        free();
        return 0;
    }
    Node<T> *t = head;
    Node<T> *s;
    int count = 2;
    while(t->next != NULL)
    {
        if(count % pos == 0)
        {
            s = t->next;
            t->next = s->next;
            delete s;
        }
        t = t->next;
        count++;
    }
    return 0;
}

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
        if (count == pos)
        {
            found = true;
            break;
        }
        t = t->next;
        count++;
    }
    if (found)
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
bool move(int pos1, int pos2)    
{
    if(head == NULL)
    {
        cout << "List is full \n";
        return -1;
    }
    int count = 0;
    Node<T> *t = head, *temp;
    while(t != NULL)
    {
        if(count == pos1 - 1)
        {
            temp = t->next;
            t->next = t->next->next;
            temp->next = NULL;
        }
        t = t->next;
    }
    insertAfterNth(temp->data, pos2);
}

template <class T>
bool SinglyLinked<T>::deleteNth(int pos)
{
    bool found = false;
    count = 1;
    if (head == NULL)
    {
        cout << "Linked list is empty \n";
        return -1;
    }
    Node<T> *t = head;
    while (t->next != NULL)
    {
        if (count == pos - 1)
        {
            found = true;
            break;
        }
        t = t->next;
    }
    if (found)
    {
        Node<T> *s = t->next;
        t->next = t->next->next;
        delete s;
    }
    else if (count == 1)
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
bool concatenate(SinglyLinked<T> &S)
{
    Node<T> *t = head;
    if(head == NULL)
    {
        head = S.head;
        return 0;
    }
    while(t->next != NULL)
        t = t->next;
    t->next = S.head
}

template <class T>
SinglyLinked<T> &combine(SinglyLinked<T> &S)
{
    
}

template <class T>
SinglyLinked<T> &union_(const SinglyLinked<T> &)
{

}

template <class T>
SinglyLinked<T> &intersection(const SinglyLinked<T> &)
{

}

int main()
{
    SinglyLinked<int> S;
    S.insBeg(5);
    S.insEnd(10);
    S.insMid(5, 6);
    S.insMid(6, 7);
    S.insMid(5, 8);
    S.display();
    S.delEnd();
    S.display();
    S.delMid(6);
    S.display();
    S.delBeg();
    S.display();
    /* code */
}