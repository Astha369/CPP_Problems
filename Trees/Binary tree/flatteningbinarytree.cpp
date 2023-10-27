#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
    if (!root) {
        return;
    }
    TreeNode* rightSubtree = root->right;
    flatten(root->left);
    root->right = root->left;
    root->left = NULL;
    TreeNode* current = root;
    while (current->right) {
        current = current->right;
    }
    current->right = rightSubtree;
    flatten(rightSubtree);
}
void printFlattenedTree(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << "Original Tree:" << endl;
    printFlattenedTree(root);
    flatten(root);
    cout << "Flattened Tree:" << endl;
    printFlattenedTree(root);
    return 0;
}
