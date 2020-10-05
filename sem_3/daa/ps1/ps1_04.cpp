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
        void levelOrder();
        int height(Node*);
        void printLevel(Node*, int);
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

int BST::height(Node* node) {  
    if (!node)  
        return 0;  

    int leftHeight = height(node->left);  
    int rightHeight = height(node->right);  
  
    if (leftHeight > rightHeight)  
        return(leftHeight + 1);  
    else return(rightHeight + 1);  
}

void BST::levelOrder() {
    int h = height(rootNode);  
    int i;  
    for (i = 1; i <= h; i++)  
        printLevel(rootNode, i);  
}

void BST::printLevel(Node* node, int level)  
{  
    if (!node)  
        return;  
    if (level == 1)  
        cout << node->key << "\t";  
    else if (level > 1) {  
        printLevel(node->left, level-1);  
        printLevel(node->right, level-1);  
    }  
} 

int main() {
    BST A;
    A.insertNode(14);
    A.insertNode(19);
    A.insertNode(2);
    A.insertNode(10);
    A.insertNode(15);
    A.levelOrder();
}