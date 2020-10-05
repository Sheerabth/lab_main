#include"SinglyLinked.hpp"

void SinglyLinked::alternate()
{
    if(head == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    SinglyLinked *S1 = new SinglyLinked();
    SinglyLinked *S2 = new SinglyLinked();
    Node *t1 = S1->head;
    Node *t2 = S2->head;   
    Node *t = head;
    count = 1;
    while(t != NULL)
    {
        Node *temp = new Node();
        temp->data = t->data;
        if(count % 2 != 0)
        {
            if(S1->head == NULL)
                S1->head = temp;
            else
                t1->next = temp;
            t1 = temp;
        }
        else
        {
            if(S2->head == NULL)
                S2->head = temp;
            else
                t2->next = temp;
            t2 = temp;
        }
        t = t->next;
        count++;
    }
    S1->display();
    S2->display();
}



Node *temp = new Node();
            temp->data = t->data;
            if(S1->head == NULL)
                S1->head = temp;
            else
                t1->next = temp;
            t1 = temp;
            t = t->next;