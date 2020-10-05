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
        int noOfLeafNodes();
        int noOfLeafNodes(Node*);
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

int BST::noOfLeafNodes() {
    return noOfLeafNodes(rootNode);
}

int BST::noOfLeafNodes(Node* node) {
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return 1;
    else
        return noOfLeafNodes(node->left) + noOfLeafNodes(node->right);
}

int main() {
    BST A;
    A.insertNode(14);
    A.insertNode(19);
    A.insertNode(2);
    A.insertNode(10);
    A.insertNode(15);
    cout << A.noOfLeafNodes();
}