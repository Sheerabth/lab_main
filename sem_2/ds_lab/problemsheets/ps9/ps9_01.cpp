#include "SinglyLinked.hpp"

void SinglyLinked::FrontBackSpit()
{
    SinglyLinked *S1 = new SinglyLinked();
    SinglyLinked *S2 = new SinglyLinked();
    Node *t1 = S1->head;
    Node *t2 = S2->head;   
    int len = noOfElements();
    if(len == 0)
    {
        cout << "List is empty \n";
        return;
    }
    else if(len == 1)
    {
        cout << "Only one element. So cant split \n";
        return;
    }
    else
    {
        bool flag = !(len % 2);
        Node *t = head;
        int count = 1;
        while(t != NULL)
        {
            Node *temp = new Node();
            temp->data = t->data;
            if(S1->head == NULL)
                S1->head = temp;
            else
                t1->next = temp;
            t1 = temp;
            t = t->next;
            if(( flag && count == len / 2) || (!flag && count == len / 2 + 1))
                break;
            count++;
            }
        }
    }  
    while(t != NULL)
    {
        Node *temp = new Node();
        temp->data = t->data;
        if(S2->head == NULL)
            S2->head = temp;
        else
            t2->next = temp;
        t2 = temp;
        t = t->next;
    }
    S1->display();
    S2->display();
}
