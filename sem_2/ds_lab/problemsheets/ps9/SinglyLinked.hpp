#include <iostream>
using namespace std;


class SinglyLinked;


class Node
{
    int data;
    Node *next;
public:
    friend SinglyLinked;
    friend SinglyLinked*& FrontBackSplit(SinglyLinked &);
    Node() : data(0), next(NULL) {}
    Node(int element) : data(element), next(NULL) {}
    Node(const Node &node) : data(node.data), next(node.next) {}
};


class SinglyLinked
{
    Node *head;

public:
    SinglyLinked() : head(NULL) {}
    int noOfElements();
    void insBeg(Node);
    bool insMid(Node, Node);
    bool insEnd(Node);
    bool delBeg();
    bool delMid(Node);
    bool delEnd();
    bool display();
    friend SinglyLinked*& FrontBackSplit(SinglyLinked &);
};

int SinglyLinked::noOfElements()
{
    int count = 0;
    Node *t = head;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}


void SinglyLinked::insBeg(Node node)
{
    Node *ptr = new Node(node);
    ptr->next = head;
    head = ptr;
}


bool SinglyLinked::insMid(Node element, Node node)
{
    Node *ptr = new Node(node);
    Node *t = head;
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


bool SinglyLinked::insEnd(Node node)
{
    Node *ptr=new Node(node);
    Node *t = head;
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


bool SinglyLinked::delBeg()
{
    Node *t = head;
    if (head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    head = head->next;
    delete t;
    return 0;
}


bool SinglyLinked::delMid(Node element)
{
    bool found = false;
    if(head == NULL)
    {
        cout << "Linked list is empty\n";
        return 0;
    }
    Node *t=head;
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
        Node *s = t->next;
        t->next = t->next->next;
        delete s;
    }
    else
        cout << "Element not found or cannot delete element\n";
    return 0;
}


bool SinglyLinked::delEnd()
{
    if(head == NULL)
    {
        cout << "The linked list is empty\n";
        return 0;
    }
    Node *t = head;
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


bool SinglyLinked::display()
{
    if(head == NULL)
    {
        cout << "The linked list is empty\n";
        return 0;
    }
    Node *t=head;
    cout << "The list contents are: \n";
    while(t != NULL)
    {
        cout << t->data << "\t";  
        t = t->next;  
    }
    cout << endl;
}
