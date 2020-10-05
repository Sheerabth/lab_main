#include<bits/stdc++.h> 
#include <vector>
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
    int getBalanceFactor(Node *node);
    Node *rootNode;
    Node* LL(Node*);
    Node* RR(Node*);
    Node* RL(Node*);
    Node* LR(Node*); 
    public:
        AVL() : rootNode(NULL) {}
        int getHeight();
        int getHeight(Node *node);
        void Search(Node);
        void insertNode(const int);
        Node* insertNode(Node*, const int);
        void inOrder();
        void inOrder(Node*);
        bool findNode(const int);
        Node* findNode(Node*, int, bool&);
};

int max(int a, int b) {
    return (a > b)? a : b;
}

int AVL::getHeight() {
    return getHeight(rootNode);
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

void AVL::insertNode(const int value) {
    rootNode = insertNode(rootNode, value);
}

Node* AVL::insertNode(Node *node, const int value) {
    if (!node) 
        return new Node(value);
    else if (value > node->key) 
        node->right = insertNode(node->right, value);
    else if (value < node->key)
        node->left = insertNode(node->left, value);
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

void AVL::inOrder() {
    inOrder(rootNode);
    cout << endl;
}

void AVL::inOrder(Node *root) {
    if(!root)
        return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

bool AVL::findNode(const int val) {
    if (!rootNode){
        cout << "Tree is empty\n";
        return false;
    }
    bool found = 0;
    rootNode = findNode(rootNode, val, found);
    if (found == 0)
        return false;
    else return true;
}

Node* AVL::findNode(Node* node, int val, bool& found) {
    if (!node)
        return node;
    if (val == node->key) {
        found = 1;
        return node;
    }
    else if (val > node->key)
        node->right = findNode(node->right, val, found);
    else if (val < node->key)
        node->left = findNode(node->left, val, found);
    return node;
}

int main() {
    AVL A;
    int no;
    cout << "Enter the no. of elements to insert: ";
    cin >> no;
    int *inp = new int[no];
    cout << "Enter the elements:\n";
    for (int i = 0; i < no; i++)
        cin >> inp[i];
    cout << "Inserting the elements\n";
    for (int i = 0; i < no; i++)
        A.insertNode(inp[i]);
    cout << "After insertion\n";
    A.inOrder();
    int val;
    cout << "Enter value to be searched in the tree: ";
    cin >> val;
    if (A.findNode(val)) 
        cout << "Node Found\n";
    else 
        cout << "Not Found\n";
}