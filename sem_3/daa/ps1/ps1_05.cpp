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
        int noOfNodes();
        int noOfNodes(Node*);
        void result(int*, int, int);
};

int BST::noOfNodes() {
    return noOfNodes(rootNode);
}

int BST::noOfNodes(Node* node) {
    if (!node)
        return 0;

    return noOfNodes(node->left) + noOfNodes(node->right) + 1;
}

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

void BST::result(int* arr, int n, int x) {
    for (int i = 0; i < n; i++)
        insertNode(arr[i]);
    int count = noOfNodes();
    if (count < x)
        cout << "Bad\n";
    else if (count > x)
        cout << "Average\n";
    else
        cout << "Good\n";
}

int main() {
    BST A;
    int n, x;
    cout << "Enter the number of integers: ";
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the number: ";
    cin >> x;
    A.result(arr, n, x);
}