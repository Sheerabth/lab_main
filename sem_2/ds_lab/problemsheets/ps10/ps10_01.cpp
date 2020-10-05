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
        bool search(int);
        bool search(Node *, const int);
        void insert(int);
        Node* insert(Node *, const int);
        void inOrder();
        void inOrder(Node *);
        void preOrder();
        void preOrder(Node *);
        void postOrder();
        void postOrder(Node *);
        int max();
        int min();
        void divByN(int);
        void divByN(Node *, const int);
        void disOdd();
        void disOdd(Node *);
        void incOrder();
        void decOrder();
        void decOrder(Node *);
        void disPrime();
        void disPrime(Node *);
};

bool BST::search(int val)
{
    return search(rootNode,val);
}

bool BST::search(Node *root, const int val)
{
    if(!root)
        return false;
    else if(val == root->data)
        return true;
    else if(val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

void BST::insert(const int val)
{
    rootNode = insert(rootNode,val);
}

Node* BST::insert(Node *root, const int val)
{
    if(!root)
        return new Node(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
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

int BST::min()
{
    if(!rootNode)
        return -1;
    Node* root = rootNode;
    while(!root->left)
        root = root->left;
    return root->data;
}

int BST::max()
{
    if(!rootNode)
        return -1;
    Node* root = rootNode;
    while(!root->right)
        root = root->right;
    return root->data;
}

void BST::divByN(int num)
{
    divByN(rootNode, num);
}

void BST::divByN(Node *root, const int num)
{
    if(!root)
        return;
    if(root->data % num == 0)
        cout << root->data << endl;
    divByN(root->left, num);
    divByN(root->right, num);
}

void BST::disOdd()
{
    disOdd(rootNode);
}

void BST::disOdd(Node *root)
{
    if(!root)
        return;
    if(root->data % 2 != 0)
        cout << root->data << endl;
    disOdd(root->left);
    disOdd(root->right);
}

void BST::incOrder()
{
    inOrder();
}

void BST::decOrder()
{
    decOrder(rootNode);
}

void BST::decOrder(Node *root)
{
    if(!root)
        return;
    decOrder(root->right);
    cout << root->data << endl;
    decOrder(root->left);
}

bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
    return true; 
} 
 

void BST::disPrime()
{
    disPrime(rootNode);
}

void BST::disPrime(Node *root)
{
    if(!root)
        return;
    if(isPrime(root->data))
        cout << root->data << endl;
    disPrime(root->left);
    disPrime(root->right);
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
    cout << "In order:\n";
    B.inOrder(); 
    cout << "Pre order:\n";
    B.preOrder(); 
    cout << "Post order:\n";
    B.postOrder();
    cout << endl << B.search(21) << endl << endl;
    B.divByN(5);
    B.incOrder();
    B.decOrder();
    B.disPrime();
}