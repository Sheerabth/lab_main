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
    SinglyLinked<T>(const SinglyLinked<T> &);            //
    SinglyLinked<T> &operator=(const SinglyLinked<T> &); //

    int noOfElements(); //
    bool display();     //
    void free();        //

    void append(Node<T>);                //
    T sumOfElements();                   //
    bool sort();                         //
    bool delEnd();                       //
    bool reverse();                      //
    bool delSecond();                    //
    bool delEveryNth(int);               //
    bool deleteNth(int);                 //
    bool move(int, int);                 //
    bool insertAfterNth(Node<T>, int);   //
    bool concatenate(SinglyLinked<T> &); //
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
            if (head == NULL)
                head = temp;
            else
                t2->next = temp;
            t2 = temp;
            t1 = t1->next;
        }
    }
}

template <class T>
SinglyLinked<T> &SinglyLinked<T>::operator=(const SinglyLinked<T> &S)
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
    if (head == NULL)
    {
        cout << "List is empty \n";
        return -1;
    }
    T temp;
    Node *t = head;
    for (Node<T> *i = head; i->next != NULL; i = i->next)
    {
        for (Node<T> *j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
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

    if (head == NULL)
    {
        cout << "List is empty \n";
        return -1;
    }
    else if (head->next == NULL)
    {
        cout << "Single element. No effect due to reversal \n";
        return 0;
    }
    Node<T> *t1 = head;
    Node<T> *t2 = t1->next;
    Node<T> *t3;
    t1->next = NULL;
    while (t3 != NULL)
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
    if (head == NULL)
    {
        cout << "List is empty \n";
        return -1;
    }
    else if (pos == 1)
    {
        free();
        return 0;
    }
    bool found = false;
    Node<T> *t = head;
    Node<T> *s;
    int count = 1;
    while (t->next != NULL)
    {
        if ((count + 1) % pos == 0)
        {
            found = true;
            s = t->next;
            t->next = s->next;
            delete s;
        }
        t = t->next;
        count++;
    }
    if (!found)
    {
        cout << "Invalid position \n";
        return -1;
    }
    return 0;
}

template <class T>
bool SinglyLinked<T>::insertAfterNth(Node<T> node, int pos)
{
    Node<T> *ptr = new Node<T>(node);
    Node<T> *t = head;
    bool found = false;
    if (head == NULL)
    {
        cout << "Linked list is empty\n";
        return -1;
    }
    int count = 1;
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
    bool found = false;
    if (head == NULL)
    {
        cout << "List is full \n";
        return -1;
    }
    else if(pos1 == 1)
    {
        temp = head;
        head = head->next;
        found = true;
    }
    else
    {
        int count = 1;
        Node<T> *t = head, *temp;
        while(t->next != NULL)
        {
            if(count == pos1 - 1)
            {
                found = true;
                temp = t->next;
                t->next = t->next->next;
                temp->next = NULL;
                break;
            }
            count++;
            t = t->next;
        }
    }
    if(found)
    {
        insertAfterNth(temp->data, pos1 + pos2 - 1);
        delete temp;
        return 0;
    }
    else
    {
        cout << "Invalid positions \n";
        return -1;
    }   
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
    SinglyLined<T> *temp = new SinglyLinked<T>();
    *temp = S;
    Node<T> *t = head;
    if (head == NULL)
    {
        head = temp->head;
        return 0;
    }
    while (t->next != NULL)
        t = t->next;
    t->next = temp->head;
    return 0;
}

template <class T>
SinglyLinked<T> &combine(SinglyLinked<T> &S)
{
    if (head == NULL && S.head == NULL)
    {
        cout << "Both lists are empty \n";
        return;
    }

    if (head == NULL)
        return S;
    else if (S.head == NULL)
        return *this;

    Node<T> *t1 = head;
    Node<T> *t2 = S.head;
    Node<T> *temp;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            while (t1->data < t2->data)
            {
                temp = t1;
                t1 = t1->next;
            }
            temp->next = t2;
        }
        else
        {
            while (t1->data > t2->data)
            {
                temp = t2;
                t2 = t2->next;
            }
            temp->next = t1;
        }
    }
    /* Should set head properly for both the lists */
    return *this;
}

template <class T>
SinglyLinked<T> &union_(const SinglyLinked<T> &S)
{
    SinglyLinked<T> *result = new SinglyLinked<T>();
    SinglyLinked<T> *list1 = new SinglyLinked<T>();
    SinglyLinked<T> *list2 = new SinglyLinked<T>();
    *list1 = *this;
    *list2 = S;
    list1->sort();
    list2->sort();
    Node<T> *t1 = list1->head;
    Node<T> *t2 = list2->head;
    Node<T> *t3 = result->head;
    while (t1 != NULL || t2 != NULL)
    {
        Node<T> *temp = new Node<T>();
        if (t1->data < t2->data)
        {
            temp->data = t1->data;
            t1 = t1->next;
        }
        else if (t2->data < t1->data)
        {
            temp->data = t2->data;
            t2 = t2->next;
        }
        else
        {
            temp->data = t1->data;
            t1 = t1->next;
            t2 = t2->next;
        }
        if (result->head == NULL)
            result->head = temp;
        else
            t3->next = temp;
        t3 = temp;
    }
    while(t1 != NULL)
    {
        Node<T> *temp = new Node<T>();
        temp->data = t1->data;
        t1 = t1->next;
        if (result->head == NULL)
            result->head = temp;
        else
            t3->next = temp;
        t3 = temp;
    }
    while(t2 != NULL)
    {
        Node<T> *temp = new Node<T>();
        temp->data = t2->data;
        t2 = t2->next;
        if (result->head == NULL)
            result->head = temp;
        else
            t3->next = temp;
        t3 = temp;
    }
    return *result;
}

template <class T>
SinglyLinked<T> &intersection(const SinglyLinked<T> &S)
{
    SinglyLinked<T> *result = new SinglyLinked<T>();
    SinglyLinked<T> *list1 = new SinglyLinked<T>();
    SinglyLinked<T> *list2 = new SinglyLinked<T>();
    *list1 = *this;
    *list2 = S;
    list1->sort();
    list2->sort();
    Node<T> *t1 = list1->head;
    Node<T> *t2 = list2->head;
    Node<T> *t3 = result->head;
    while (t1 != NULL || t2 != NULL)
    {
        Node<T> *temp = new Node<T>();
        if (t1->data < t2->data)
        {
            t1 = t1->next;
            continue;
        }
        else if (t2->data < t1->data)
        {
            t2 = t2->next;
            continue;
        }
        else
        {
            temp->data = t1->data;
            t1 = t1->next;
            t2 = t2->next;
        }
        if (result->head == NULL)
            result->head = temp;
        else
            t3->next = temp;
        t3 = temp;
    }
    return *result;
}

int main()
{
    int ch, select = 0, element;
    SinglyLinkedList<int> list[6];

    while (1)
    {
        cout << "1) Append an element to the end of a list\n"
                "2) Concatenate two lists\n"
                "3) Free all the nodes in a list\n"
                "4) Reverse a list, so that the last element becomes the first, and so on. \n"
                "5) Delete the last element from a list\n"
                "6) Delete the nth element from a list\n"
                "7) Combine two ordered lists into a single ordered list\n"
                "8) Form a list containing the union of the elements of two lists\n"
                "9) Form a list containing the intersection of the elements of two lists\n"
                "10) Insert an element after the nth element of a list\n"
                "11) Delete every second element from a list\n"
                "12) Place the elements of a list in increasing order\n"
                "13) Return the sum of the integers in a list\n"
                "14) Return the number of elements in a list\n"
                "15) Move node(p) forward n positions in a list\n"
                "16) Make a second copy of a list \n";

        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Select the list : ";
            cin >> select;
            cout << "Append an element to the end of a list: ";
            cin >> element;
            list[select % 6].append(element);
            break;
        case 2:
            list[0].concatenate(list[1]);
            break;
        case 3:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].free();
            break;
        case 4:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].reverse();
            break;
        case 5:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].deleteEnd();
            break;
        case 6:
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            list[select % 6].deleteNth(element);
            break;
        case 7:
            list[3] = list[0].combine(list[1]);
            break;
        case 8:
            list[4] = list[0].union_(list[1]);
            break;
        case 9:
            list[5] = list[0].intersection(list[1]);
            break;
        case 10:
            int data;
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            cout << "Enter the value of data ";
            cin >> data;
            list[select % 6].insertAfterNth(element, data);
            break;
        case 11:
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            list[select % 6].deleteEveryNth(element);
            break;
        case 12:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].sort();
            break;
        case 13:
            cout << "Select the list : ";
            cin >> select;
            cout << "\nThe sum is : " << list[select % 6].sumOfElements();
            break;
        case 14:
            cout << "Select the list : ";
            cin >> select;
            cout << "\nThe Number of elements is : " << list[select % 6].noOfElements();
            break;
        case 15:
            int pos1, pos2;
            cout << "Select the list : ";
            cin >> select;  
            cout << "Enter the position of the node to be moved: ";
            cin >> pos1;
            cout << "Enter the no. of positions to be moved: ";
            cin >> pos2;
            listmove()
            break;
        case 16:
            cout << "Select the list : ";
            cin >> select;
            list[5] = list[select % 6];
        case 0:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].display();
            break;
        default:
            exit(0);
        }
    }
}