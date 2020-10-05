#include "BST.hpp"

void BST::mirror()
{
    mirror(rootNode);
}

void BST::mirror(Node *root)
{
    if(!root)
        return;
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

int main()
{
    BST B;
    B.insert(4); 
    B.insert(2);
    B.insert(5);
    B.insert(1);
    B.insert(3);
    cout << "In order:\n";
    B.inOrder(); 
    B.mirror();
    cout << "In order:\n";
    B.inOrder();
}