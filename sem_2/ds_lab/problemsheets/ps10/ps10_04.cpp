#include "BST.hpp"
#include<vector>

vector<int> v;
int i = 0;

int BST::maxDepth()
{
    maxDepth(rootNode);
}

int BST::maxDepth(Node *root)
{
    if(!root)
        return;
    if(!root->left && !root->right)
    {
        v.push_back(1);
        return i++;
    }
    v[maxDepth(root->left)]++;
    v[maxDepth(root->right)]++;
}

int main()
{
    BST B;
    B.insert(5); 
    B.insert(15);
    B.insert(0);
    B.insert(123);
    B.insert(9);
    B.insert(13);
    B.insert(43);
    B.insert(198);
    B.insert(2);
    B.insert(109);
    B.maxDepth();
}