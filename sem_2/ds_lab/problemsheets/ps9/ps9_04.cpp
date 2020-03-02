#include"SinglyLinked.hpp"

void SinglyLinked::altMerge(SinglyLinked &S)
{
    if(head == NULL && S.head == NULL)
    {
        cout << "Both lists empty\n";
        return;
    }
    Node *t1 = head;
    Node *t2 = S.head;
    while(t1 != NULL || )
}