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
        void deleteMinNode();
        void deleteRootNode();
        void findNode(const int);
        Node* findNode(Node*, int, bool&);
        int noOfLeafNodes();
        int noOfLeafNodes(Node*);
        void listBtwValues(int, int);
        void listBtwValues(Node*, int, int);
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
        return RL(node);
    if (balancefactor < 1 && getBalanceFactor(node->right) <= 0)
        return RR(node);
    if (balancefactor < 1 && getBalanceFactor(node->right) > 0)
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

void AVL::deleteMinNode() {
    if (!rootNode) 
        return;
    Node* node = rootNode;
    while (node->left != NULL) {
        node = node->left;
    }
    rootNode = deleteNode(rootNode, node->key);
}

void AVL::deleteRootNode() {
    rootNode = deleteNode(rootNode, rootNode->key);
}

void AVL::findNode(const int val) {
    if (!rootNode){
        cout << "Tree is empty\n";
        return;
    }
    bool found = 0;
    rootNode = findNode(rootNode, val, found);
    if (found == 0)
        cout << "Not Found";
}

Node* AVL::findNode(Node* node, int val, bool& found) {
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

int AVL::noOfLeafNodes() {
    return noOfLeafNodes(rootNode);
}

int AVL::noOfLeafNodes(Node* node) {
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return 1;
    else
        return noOfLeafNodes(node->left) + noOfLeafNodes(node->right);
}

void AVL::listBtwValues(int a, int b) {
    listBtwValues(rootNode, a, b);
}

void AVL::listBtwValues(Node* node, int a, int b) {
    if (!node)
        return;
    if (a < node->key)
        listBtwValues(node->left, a, b);
    if (a < node->key && b > node->key)
        cout << node->key << " ";
    if (b > node->key)
        listBtwValues(node->right, a, b);
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
    
}