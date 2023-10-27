#include <iostream>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

int getHeight(AVLNode* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* createNewNode(int data) {
    AVLNode* newNode = new AVLNode();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1; // New node is initially at height 1
    return newNode;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int getBalance(AVLNode* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* insert(AVLNode* root, int data) {
    if (root == nullptr) return createNewNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else // Duplicate keys are not allowed
        return root;

    // Update height of current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor of this node to check if it became unbalanced
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrderTraversal(AVLNode* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    AVLNode* root = nullptr;
    int n, element;
    
    cout << "Enter the number of elements to insert: ";
    cin >> n;

    cout << "Enter the elements to insert:\n";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        root = insert(root, element);
    }

    cout << "AVL Tree (Preorder Traversal): ";
    preOrderTraversal(root);

    return 0;
}
