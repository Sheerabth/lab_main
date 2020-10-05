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

void AVL::preOrder() {
    preOrder(rootNode);
    cout << endl;
}

void AVL::preOrder(Node *root) {
    if(!root)
        return;
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void AVL::postOrder() {
    postOrder(rootNode);
    cout << endl;
}

void AVL::postOrder(Node *root) {
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " ";
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
    for (int i = 0; i < no; i++) {
        A.insert(inp[i]);
        cout << "Tree after insertion of element " << inp[i] << endl;
        A.inOrder();
    }
}