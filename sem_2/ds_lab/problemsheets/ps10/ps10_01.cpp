#include<iostream>
using namespace std;

class BST;

class Node
{
    int data;
    Node *right, *left;
    friend class BST;
    public:
        Node():data(0),left(NULL),right(NULL){}
        Node(int dat):data(dat),left(NULL),right(NULL){}
};

class BST
{
    Node *baseRoot;
    public:
        BST():root(NULL){}
        void insert(Node *&, const int&);
        bool search(Node *&root)
};

void BST::insert(Node *& root, const int &val)
{
    if(!baseRoot)
    {
        baseRoot->data = val;
        return;
    }
    else if(!root)
    {
        root->data = val;
        return;
    }
    else if(root->data < val)
        insert(root->right, val);
    else
        insert(root->left, val);
}

int main()
{
    Node *temp = new Node();
    BST B;
    B.insert(temp,5);
    B.insert(temp,)
}

