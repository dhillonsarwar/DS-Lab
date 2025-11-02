#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() : root(nullptr) {}

  

    void preorder(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};
