#include<iostream>
using namespace std;

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
    Node* rootNode;
    public:
        BST():rootNode(NULL){}
        void insert(int);
        Node* insert(Node *, const int);
        void inOrder();
        void inOrder(Node *);
        void preOrder();
        void preOrder(Node *);
        void postOrder();
        void postOrder(Node *);
};

void BST::insert(const int val)
{
    rootNode = insert(rootNode,val);
}

Node* BST::insert(Node *root, const int val)
{
    if(!root)
        return new Node(val);
    if(root->data < val)
        root->right = insert(root->right, val);
    else
        root->left = insert(root->left, val);
    return root;
}

void BST::inOrder()
{
    inOrder(rootNode);
}

void BST::inOrder(Node *root)
{
    if(!root)
        return;
    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
}

void BST::preOrder()
{
    preOrder(rootNode);
}

void BST::preOrder(Node *root)
{
    if(!root)
        return;
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
}

void BST::postOrder()
{
    postOrder(rootNode);
}

void BST::postOrder(Node *root)
{
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
}

