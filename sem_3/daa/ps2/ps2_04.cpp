#include<iostream>
using namespace std;

#define COUNT 10

class Tree;

class Node {
    int key;
    Node *right, *left;
    friend class Tree;
    public:
        Node():key(0),left(NULL),right(NULL){}
        Node(int dat):key(dat),left(NULL),right(NULL){}
        friend void change(Tree&, Tree&);
        friend void change(Node*&, Node*&);
        friend Node* LL(Node*);
        friend Node* RR(Node*);
        friend Node* LR(Node*);
        friend Node* RL(Node*);
};

class Tree {   
    Node* rootNode;
    public:
        Tree():rootNode(NULL){}
        void insertNode(const int);
        Node* insertNode(Node*, const int);
        void deleteMinNode();
        Node* deleteMinNode(Node*);
        void print2DUtil();
        void print2DUtil(Node *root, int space);
        friend void change(Tree&, Tree&);
        friend void change(Node*&, Node*&);
};

Node* LL(Node *A) {
    Node *k = new Node();
    k = A->left;
    A->left = k->right;
    k->right = A; 
    return k;
}

Node* RR(Node *A) {
    Node *k = new Node();
    k = A->right;
    A->right = k->left;
    k->left = A;
    return k;
}

Node* LR(Node *A) {
    A->left = RR(A->left);
    Node *k = new Node();
    k = LL(A);
    return k;
}

Node* RL(Node *A) {
    A->right = LL(A->right);
    Node *k = new Node();
    k = RR(A);
    return k;
}

void Tree::insertNode(const int key) {
    rootNode = insertNode(rootNode,key);
}

Node* Tree::insertNode(Node* node, const int key) {
    if (!node)
        return new Node(key);
    if (node->key < key)
        node->right = insertNode(node->right, key);
    else if (node->key > key)
        node->left = insertNode(node->left, key);
    return node;
}

void Tree::deleteMinNode() {
    if (!rootNode){
        cout << "Tree is empty\n";
        return;
    }
    rootNode = deleteMinNode(rootNode);
}

Node* Tree::deleteMinNode(Node* node) {
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

void Tree::print2DUtil() {
    print2DUtil(rootNode, 0);
}

void Tree::print2DUtil(Node *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);
    cout<<endl;
    
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->key <<"\n";

    print2DUtil(root->left, space);
}

void change(Tree& T1, Tree& T2) {
    change(T1.rootNode, T2.rootNode);
}

void change(Node*& node1, Node*& node2) {

    if (node1 != NULL) {
        if (node2 != NULL) {
        
            while(node1->key != node2->key) {

                if(node1->key > node2->key) {

                    if(node1->left != NULL && node1->left->right != NULL && node1->left->right->key == node2->key) {
                        cout << "LR is performed in node " << node1->key << endl;
                        node1 = LR(node1);
                    }

                    if(node1->right != NULL || node1->left != NULL) {
                        cout << "LL is performed in node " << node1->key << endl;
                        node1 = LL(node1);
                    }

                }
                else if(node1->key < node2->key) {

                    if(node1->right != NULL && node1->right->left != NULL && node1->right->left->key == node2->key) {
                        cout << "RL is performed in node " << node1->key << endl;
                        node1 = RL(node1);
                    }

                    if(node1->right != NULL || node1->left != NULL) {
                        cout << "RR is performed in node " << node1->key << endl;
                        node1 = RR(node1);
                    }
                    
                }
            }
            change(node1->left, node2->left);
            change(node1->right, node2->right);
        }
    }
} 

int main() {
    Tree T1, T2;
    int no1, no2, temp;
    cout << "Enter the no. of elements in Tree 1: ";
    cin >> no1;
    cout << "Enter the elements:\n";
    for (int i = 0; i < no1; i++) {
        cin >> temp;
        T1.insertNode(temp);
    }

    cout << "Enter the no. of elements in Tree 2: ";
    cin >> no2;
    cout << "Enter the elements:\n";
    for (int i = 0; i < no2; i++) {
        cin >> temp;
        T2.insertNode(temp);
    }

    cout << "Tree 1:\n";
    T1.print2DUtil();
    cout << "Tree 2:\n";    
    T2.print2DUtil();
    change(T1, T2);
    cout << "Tree 1 after change:\n";
    T1.print2DUtil();
}