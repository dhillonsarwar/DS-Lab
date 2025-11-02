#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node *root;
    BST() : root(nullptr) {}

    Node* insert(Node* root, int val) {
        if (!root)
            return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);
        return root;
    }

    Node* searchRecursive(Node* root, int key) {
        if (!root || root->data == key)
            return root;
        if (key < root->data)
            return searchRecursive(root->left, key);
        else
            return searchRecursive(root->right, key);
    }

    Node* searchNonRecursive(Node* root, int key) {
        while (root) {
            if (root->data == key)
                return root;
            else if (key < root->data)
                root = root->left;
            else
                root = root->right;
        }
        return nullptr;
    }

    Node* findMin(Node* root) {
        while (root && root->left)
            root = root->left;
        return root;
    }

    Node* findMax(Node* root) {
        while (root && root->right)
            root = root->right;
        return root;
    }

    Node* inorderSuccessor(Node* root, Node* node) {
        if (node->right)
            return findMin(node->right);
        Node* succ = nullptr;
        while (root) {
            if (node->data < root->data) {
                succ = root;
                root = root->left;
            } else if (node->data > root->data) {
                root = root->right;
            } else break;
        }
