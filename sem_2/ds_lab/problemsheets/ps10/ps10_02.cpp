#include"BST.hpp"

bool sameTrees(Node *A, Node *B)
{
    if(!A && !B)
        return true;
    if( A && B )
        return
        (
            A->data == B->data &&
            sameTrees(A->left, B->left) &&
            sameTrees(A->right, B->right)
        );
    return false;
}

bool BST::sameTrees(BST &B)
{
    return ::sameTrees(rootNode, B.rootNode);
}

int main()
{
    BST B;
    B.insert(5); 
    B.insert(15);
    B.insert(0);
    B.insert(123);
    B.insert(9);
    B.insert(13);
    B.insert(43);
    B.insert(198);
    B.insert(2);
    B.insert(109);
    BST A;
    A.insert(5); 
    A.insert(15);
    A.insert(0);
    A.insert(123);
    A.insert(5);
    A.insert(13);
    A.insert(43);
    A.insert(198);
    A.insert(2);
    A.insert(109);
    cout << A.sameTrees(B);
}