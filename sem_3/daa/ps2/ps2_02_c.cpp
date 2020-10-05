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
        void deleteNode(const int);
        Node* deleteNode(Node*, const int);
        void insertNode(const int);
        Node* insertNode(Node*, const int);
        void inOrder();
        void inOrder(Node*);
        void deleteRootNode();
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

void AVL::deleteNode(const int value) {
    rootNode = deleteNode(rootNode, value);
}

Node* AVL::deleteNode(Node *node, const int value) {
    if (!node)
        return node;
    if (value < node->key)
        node->left = deleteNode(node->left, value);
    else if (value > node->key)
        node->right = deleteNode(node->right, value);
    else {
        if (node->right == NULL && node->left == NULL) {
            Node *temp = new Node();
            *temp = *node;
            node = NULL;
            free(temp);

        }
        else if (node->right == NULL || node->left == NULL) {
            Node* temp = new Node();
            temp = node->left ? node->left : node->right;
            *node = *temp;
            free(temp);
        }
        else {
            Node* temp = node->left;
            while(temp->right != NULL)
                temp = temp->right;
            node->key = temp->key;
            node->left = deleteNode(node->left, temp->key);
        }
    }

    if (!node)
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balancefactor = getBalanceFactor(node);

    if (balancefactor > 1 && getBalanceFactor(node->left) >= 0)
        return LL(node);
    if (balancefactor > 1 && getBalanceFactor(node->left) < 0)
        return LR(node);
    if (balancefactor < -1 && getBalanceFactor(node->right) <= 0)
        return RR(node);
    if (balancefactor < -1 && getBalanceFactor(node->right) > 0)
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

void AVL::deleteRootNode() {
    rootNode = deleteNode(rootNode, rootNode->key);
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
    cout << "Before Deletion\n";
    A.inOrder();
    A.deleteRootNode();
    cout << "After Deletion\n";
    A.inOrder();   
}