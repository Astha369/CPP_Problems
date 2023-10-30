#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left, *right, *parent;

    Node(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr)
            x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        x->right = y;
        y->parent = x;
    }

    void fixInsert(Node* k) {
        Node* u;
        while (k->parent != nullptr && k->parent->color == RED) {
            if (k->parent == k->parent->parent->left) {
                u = k->parent->parent->right;
                if (u != nullptr && u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        rotateLeft(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rotateRight(k->parent->parent);
                }
            } else {
                u = k->parent->parent->left;
                if (u != nullptr && u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rotateRight(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rotateLeft(k->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void preOrder(Node* node) {
      if (node == nullptr)
        return;
      cout << "(" << (node->color == RED ? "RED" : "BLACK") << ")" << node->data << " ";
      preOrder(node->left);
      preOrder(node->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int val) {
        Node* new_node = new Node(val);
        Node* parent = nullptr;
        Node* current = root;
        while (current != nullptr) {
            parent = current;
            if (val < current->data)
                current = current->left;
            else
                current = current->right;
        }
        new_node->parent = parent;
        if (parent == nullptr)
            root = new_node;
        else if (val < parent->data)
            parent->left = new_node;
        else
            parent->right = new_node;
        fixInsert(new_node);
    }

    void preOrderTraversal() {
        cout << "Pre-order Traversal: ";
        preOrder(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree rbt;
    int num_elements;
    cout << "Enter the number of elements to insert: ";
    cin >> num_elements;

    cout << "Enter the elements to insert: ";
    for (int i = 0; i < num_elements; ++i) {
        int num;
        cin >> num;
        rbt.insert(num);
    }

    rbt.preOrderTraversal();

    return 0;
}
