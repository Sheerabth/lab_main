#include "SinglyLinked.hpp"

SinglyLinked*& FrontBackSpit(SinglyLinked &S1)
{
    SinglyLinked *S2 = new SinglyLinked();   
    int len = S1.noOfElements();
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
        Node *t = head;
        int count = 1;
        while(t != NULL)
        {
            if(count == len/2)
                break;
            else
            {
                t = t->next;
                count++;
            }
        }
    }
    
}