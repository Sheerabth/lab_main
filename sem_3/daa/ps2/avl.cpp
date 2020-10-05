#include <iostream>
using namespace std;

class AVL;

class Node{
    int key;
    int height;
    Node *left, *right;
    public:
        friend AVL;
        Node() : key(0), height(1), left(NULL), right(NULL) {}
        Node(int element) : key(element), height(1), left(NULL), right(NULL) {}
        Node(const Node &node) : key(node.key), height(node.height), left(node.left), right(node.right) {}
};

class AVL{
    int getHeight(Node *node);
    int getBalanceFactor(Node *node);
    Node *rootNode;
    Node* LL(Node*);
    Node* RR(Node*);
    Node* RL(Node*);
    Node* LR(Node*); 
    public:
        AVL() : rootNode(NULL) {}
        void Search(Node);
        void Delete(const int);
        Node* Delete(Node*, const int);
        void insert(const int);
        Node* insert(Node*, const int);
        void inOrder();
        void inOrder(Node*);
        void preOrder();
        void preOrder(Node*);
        void postOrder();
        void postOrder(Node*);
};

int max(int a, int b) {
    return (a > b)? a : b;
}

int AVL::getHeight(Node* node) {
    if(!node)
        return 0;
    return node->height;
}

int AVL::getBalanceFactor(Node *node) {
    if (!node) 
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* AVL::LL(Node *A) {
    Node *k = new Node();
    k = A->left;
    A->left = k->right;
    k->right = A; 
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
    k->height = max(getHeight(k->left), getHeight(k->right)) + 1;
    return k;
}

Node* AVL::RR(Node *A) {
    Node *k = new Node();
    k = A->right;
    A->right = k->left;
    k->left = A;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
    k->height = max(getHeight(k->left), getHeight(k->right)) + 1;
    return k;
}

Node* AVL::LR(Node *A) {
    A->left = RR(A->left);
    Node *k = new Node();
    k = LL(A);
    return k;
}

Node* AVL::RL(Node *A) {
    A->right = LL(A->right);
    Node *k = new Node();
    k = RR(A);
    return k;
}

void AVL::insert(const int value) {
    rootNode = insert(rootNode, value);
}

Node* AVL::insert(Node *node, const int value) {
    if (!node) 
        return new Node(value);
    else if (value > node->key) 
        node->right = insert(node->right, value);
    else if (value < node->key)
        node->left = insert(node->left, value);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balancefactor = getBalanceFactor(node);

    if (balancefactor > 1 && value < node->left->key)
        return LL(node);
    if (balancefactor > 1 && value > node->left->key)
        return LR(node);
    if (balancefactor < -1 && value > node->right->key)
        return RR(node);
    if (balancefactor < -1 && value < node->right->key)
        return RL(node);
    
    return node;
}

void AVL::Delete(const int value) {
    rootNode = Delete(rootNode, value);
}

Node* AVL::Delete(Node *node, const int value) {
    if (!node)
        return node;
    else if (value > node->key)
        node->right = Delete(node->right, value);
    else if (value < node->key)
        node->left = Delete(node->right, value);
    else {
        if (node->right == NULL && node->left == NULL) {
            Node *temp = new Node();
            *temp = *node;
            node = NULL;
            delete temp;

        }
        else if (node->right == NULL || node->left == NULL) {
            Node* temp = node;
            node = node->left ? node->left : node->right;
            delete temp;
        }
        else {
            Node* temp = node->left;
            while(temp->right != NULL)
                temp = temp->right;
            *node = *temp;
            node->left = Delete(node->left, temp->key);
        }
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balancefactor = getBalanceFactor(node);

    if (balancefactor > 1 && getBalanceFactor(node->left) >= 0)
        return LL(node);
    if (balancefactor > 1 && getBalanceFactor(node->left) < 0)
        return RL(node);
    if (balancefactor < 1 && getBalanceFactor(node->right) <= 0)
        return RR(node);
    if (balancefactor < 1 && getBalanceFactor(node->right) > 0)
        return RL(node);
    
    return node;
}

void AVL::inOrder() {
    inOrder(rootNode);
}

void AVL::inOrder(Node *root) {
    if(!root)
        return;
    inOrder(root->left);
    cout << root->key << endl;
    inOrder(root->right);
}

void AVL::preOrder() {
    preOrder(rootNode);
}

void AVL::preOrder(Node *root) {
    if(!root)
        return;
    cout << root->key << endl;
    preOrder(root->left);
    preOrder(root->right);
}

void AVL::postOrder() {
    postOrder(rootNode);
}

void AVL::postOrder(Node *root) {
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << endl;
}

