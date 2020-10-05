#include <iostream>
using namespace std;

class Splay;

class Node {
    int key;
    Node *left, *right;
    public:
        friend Splay;
        Node() : key(0), left(NULL), right(NULL) {}
        Node(int element) : key(element), left(NULL), right(NULL) {}
        Node(const Node &node) : key(node.key), left(node.left), right(node.right) {}
};

class Splay {
    Node *rootNode;
    Node* LL(Node*);
    Node* RR(Node*);
    Node* RL(Node*);
    Node* LR(Node*); 
    public:
        Splay() : rootNode(NULL) {}
        void Search(Node);
        void deleteNode(const int);
        void deleteNode(const int);
        void insertNode(const int);
        Node* insertNode(Node*, const int);
        Node* splayNode(Node*, const int);
};

Node* Splay::LL(Node *A) {
    Node* k = A->left;
    A->left = k->right;
    k->right = A; 
    return k;
}

Node* Splay::RR(Node *A) {
    Node* k = A->right;
    A->right = k->left;
    k->left = A;
    return k;
}

void Splay::insertNode(const int value) {
    rootNode = insertNode(rootNode, value);
}

Node* Splay::insertNode(Node* node, const int value) {
    if (!node) 
        return new Node(value);
    else if (value > node->key) 
        node->right = insertNode(node->right, value);
    else if (value < node->key)
        node->left = insertNode(node->left, value);
    else
        return node;

    if (node->right != NULL && node->right->key == value)
        return RR(node);
    if (node->left != NULL && node->left->key == value)
        return LL(node);
}

void Splay::deleteNode(const int value) {

    rootNode = splayNode(rootNode, value);

    if (rootNode->right == NULL && rootNode->left == NULL) {
        Node *temp = new Node();
        *temp = *rootNode;
        rootNode = NULL;
        delete temp;

    }
    else if (rootNode->right == NULL || rootNode->left == NULL) {
        Node* temp = rootNode;
        rootNode = rootNode->left ? rootNode->left : rootNode->right;
        delete temp;
    }
    else {
        Node* lnode = rootNode->left;
        Node* rnode = rootNode->right;
        while(lnode->right != NULL)
            lnode = lnode->right;
        rootNode = splayNode(rootNode, lnode->key);
        Node* temp = rootNode->right;
        rootNode->right = rnode;
        delete temp;
    }
}

Node* Splay::splayNode(Node* node, const int value) {
    if (!node) 
        return node;
    else if (value > node->key) 
        node->right = splayNode(node->right, value);
    else if (value < node->key)
        node->left = splayNode(node->left, value);
    else
        return node;

    if (node->right != NULL && node->right->key == value)
        return RR(node);
    if (node->left != NULL && node->left->key == value)
        return LL(node);

    return node;
}