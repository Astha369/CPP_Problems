/*
Depth first search
Preorder traversal
Root-->Left-->Right
tc-O(n) sc-O(n)
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

void preorder(struct node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    preorder(root);

    return 0;
}