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
        void findNode(const int);
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

void BST::findNode(const int value) {
    if (!rootNode)
        cout << "NO\n";
    bool found = 0;
    Node* node = rootNode;
    while (node) {
        if (value < node->key)
            node = node->left;
        else if (value > node->key)
            node = node->right;
        else if(value == node->key) {
            cout << "YES\n";
            found = 1;
            break;
        }
    }
    if (found == 0)
        cout << "NO\n";
}

int main() {
    BST B;
    int no, key;
    cout << "Enter the no. of students in class: ";
    cin >> no;
    int *inp = new int[no];
    cout << "Enter the no. of candies each child has:\n";
    for (int i = 0; i < no; i++)
        cin >> inp[i];
    cout << "Inserting the elements into the BST\n";
    for (int i = 0; i < no; i++)
        B.insertNode(inp[i]);
    cout << "Enter the no. of candies the new child has: ";
    cin >> key;
    B.findNode(key);
}