#include"SinglyLinked.hpp"

void SinglyLinked::removeDuplicates()
{
    if(head == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    Node *t = head;
    while(t->next != NULL)
    {
        if(t->data == t->next.data)
            t->next = t->next->next;
        else
            t = t->next;
    }
}