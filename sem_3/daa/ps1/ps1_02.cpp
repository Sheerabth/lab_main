#include<iostream>
using namespace std;

class Node {
    int key;
    Node *right, *left;
    friend class BST;
    public:
        Node():key(0),left(NULL),right(NULL){}
        Node(int dat):key(dat),left(NULL),right(NULL){}
};

class BST {   
    Node* rootNode;
    public:
        BST():rootNode(NULL){}
        void insertNode(const int);
        Node* insertNode(Node*, const int);
        int findIterations(int);
};

void BST::insertNode(const int val) {
    rootNode = insertNode(rootNode,val);
}

Node* BST::insertNode(Node* node, const int val) {
    if (!node)
        return new Node(val);
    if (node->key < val)
        node->right = insertNode(node->right, val);
    else if (node->key > val)
        node->left = insertNode(node->left, val);
    return node;
}

int BST::findIterations(int val) {
    if (!rootNode) 
        return -1;
    Node* node = rootNode;
    int count = 0;
    while (node) {
        count++;
        if (val == node->key)
            return count;
        else if (val < node->key)
            node = node->left;
        else if (val > node->key)
            node = node->right;
    }
    return count;
}

int main() {
    BST A;
    A.insertNode(1);
    A.insertNode(2);
    A.insertNode(3);
    A.insertNode(4);
    A.insertNode(5);
    A.insertNode(6);
    A.insertNode(7);
    A.insertNode(8);
    A.insertNode(9);
    A.insertNode(10);
    cout << A.findIterations(5);
}