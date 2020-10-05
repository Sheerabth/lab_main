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
        void deleteMinNode();
        Node* deleteMinNode(Node*);
        void findNode(const int);
        Node* findNode(Node*, const int, bool&);
        int findMax();
        Node* getLeft(Node* node);
        Node* getRight(Node* node);
        void inOrder();
        void inOrder(Node *);
        void preOrder();
        void preOrder(Node *);
        void postOrder();
        void postOrder(Node *);
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

void BST::deleteMinNode() {
    if (!rootNode){
        cout << "Tree is empty\n";
        return;
    }
    rootNode = deleteMinNode(rootNode);
}

Node* BST::deleteMinNode(Node* node) {
    if (!node)
        return node;
    if (node->left != NULL) {
        node->left = deleteMinNode(node->left);
    }
    else {
        Node* temp = node->right;
        delete node;
        return temp;
    }
    return node;
}

void BST::findNode(const int val) {
    if (!rootNode){
        cout << "Tree is empty\n";
        return;
    }
    bool found = 0;
    rootNode = findNode(rootNode, val, found);
    if (found == 0)
        cout << "Not Found";
}

Node* BST::findNode(Node* node, int val, bool& found) {
    if (!node)
        return node;
    if (val == node->key) {
        cout << "Found" << endl;
        found = 1;
        return node;
    }
    else if (val > node->key)
        node->right = findNode(node->right, val, found);
    else if (val < node->key)
        node->left = findNode(node->left, val, found);
    return node;
}

int BST::findMax() {
    if (!rootNode){
        cout << "Tree is empty\n";
        return 0;
    }
    Node* node = rootNode;
    while(node->right != NULL) {
        node = node->right;
    }
    return node->key;
}

Node* BST::getLeft(Node *node) {
    if (!node){
        cout << "Invalid node\n";
        return NULL;
    }
    return node->left;
}

Node* BST::getRight(Node *node) {
    if (!node){
        cout << "Invalid node\n";
        return NULL;
    }
    return node->right;
}

void BST::inOrder() {
    if (!rootNode){
        cout << "Tree is empty\n";
        return;
    }
    inOrder(rootNode);
}

void BST::inOrder(Node *node) {
    if(!node)
        return;
    inOrder(node->left);
    cout << node->key << endl;
    inOrder(node->right);
}

void BST::preOrder() {
    if (!rootNode){
        cout << "Tree is empty\n";
        return;
    }
    preOrder(rootNode);
}

void BST::preOrder(Node *node) {
    if(!node)
        return;
    cout << node->key << endl;
    preOrder(node->left);
    preOrder(node->right);
}

void BST::postOrder() {
    if (!rootNode){
        cout << "Tree is empty\n";
        return;
    }
    postOrder(rootNode);
}

void BST::postOrder(Node *node) {
    if(!node)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->key << endl;
}

int main() {
    BST A;
    A.insertNode(12);
    A.insertNode(2);
    A.insertNode(21);
    A.insertNode(15);
    A.inOrder();
    A.findNode(12);
}