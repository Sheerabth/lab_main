#include"SinglyLinked.hpp"

SinglyLinked& SinglyLinked::ShuffleMerge(SinglyLinked &S)
{
    if(head == NULL && S.head == NULL)
    {
        cout << "Both lists empty\n";
        return;
    }
    SinglyLinked * result = new SinglyLinked();
    Node *t1 = head;
    Node *t2 = S.head;
    while(t1 != NULL || t2 != NULL)
    {
        Node *temp = new Node();
        Node *t = result->head;
        if(t1->data < t2->data)
            temp->data = t1->data;
        else
            temp->data = t2->data;
        if(result->head == NULL)
            result->head = temp;
        else
            t->next = temp;
        t = temp;
    }
    while(t1 != NULL)
    {
        Node *temp = new Node();
        Node *t = result->head;
        temp->data = t1->data;
        if(result->head == NULL)
            result->head = temp;
        else
            t->next = temp;
        t = temp;
    }
    while(t2 != NULL)
    {
        Node *temp = new Node();
        Node *t = result->head;
        temp->data = t2->data;
        if(result->head == NULL)
            result->head = temp;
        else
            t->next = temp;
        t = temp;
    }
    return *result;
}