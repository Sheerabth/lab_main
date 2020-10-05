#include<iostream>
#include<vector>
#define COUNT 10
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
    void treeToList(Node*, vector<int>&);
    Node* listToTree(vector<int>&, int, int);
    vector<int> mergeLists(vector<int>&, vector<int>&);

    public:
        Node* rootNode;
        BST():rootNode(NULL){}
        void insertNode(const int);
        Node* insertNode(Node*, const int);
        void mergeTrees(Node*, Node*);
        void inOrder();
        void inOrder(Node*);
        void print2DUtil();
        void print2DUtil(Node*, int);
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

void BST::treeToList(Node* node, vector<int> &list) {
    if (!node) 
        return;
    
    treeToList(node->left, list);
    list.push_back(node->key);
    treeToList(node->right, list);
}

Node* BST::listToTree(vector<int> &list, int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node* node = new Node(list[mid]);
    node->left = listToTree(list, start, mid-1);
    node->right = listToTree(list, mid+1, end);
    return node;
}

vector<int> BST::mergeLists(vector<int> &list1, vector<int> &list2) {
    vector<int> list;
    int i = 0;
    int j = 0;
    while (i < list1.size() && j < list2.size()) {
        if (list1[i] < list2[j]) {
            list.push_back(list1[i]);
            i++;
        }
        else if (list1[i] > list2[j]){
            list.push_back(list2[j]);
            j++;
        }
        else {
            list.push_back(list1[i]);
            i++;
            j++;
        }
    }
    while (i < list1.size()) {
        list.push_back(list1[i]);
        i++;
    }
    while (j < list2.size()) {
        list.push_back(list2[j]);
        j++;
    }
    return list;
}

void BST::mergeTrees(Node* root1, Node* root2) {
    vector<int> list1, list2;
    treeToList(root1, list1);
    treeToList(root2, list2);
    vector<int> list3 = mergeLists(list1, list2);
    rootNode = listToTree(list3, 0, list3.size()-1);
}

void BST::inOrder() {
    inOrder(rootNode);
    cout << endl;
}

void BST::inOrder(Node *root) {
    if(!root)
        return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

void BST::print2DUtil() {
    print2DUtil(rootNode, 0);
}

void AVL::print2DUtil(Node *root, int space)
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

int main() {
    BST A, B, C;
    int n1, n2;
    cout << "Enter no of elements in 1st tree: ";
    cin >> n1;
    int temp;
    cout << "Enter elements of 1st tree:\n";
    for (int i = 0; i < n1; i++) {
        cin >> temp;
        A.insertNode(temp);
    }
    cout << "Enter no of elements in 2nd tree: ";
    cin >> n2;
    cout << "Enter elements of qnd tree:\n";
    for (int i = 0; i < n2; i++) {
        cin >> temp;
        B.insertNode(temp);
    }
    A.inOrder();
    B.inOrder();
    C.mergeTrees(A.rootNode, B.rootNode);
    C.inOrder();
}