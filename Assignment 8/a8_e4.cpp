#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool small(Node* root, Node* L) {
    if (!L) return true;
    return (L->data < root->data) && small(root, L->left) && small(root, L->right);
}

bool large(Node* root, Node* R) {
    if (!R) return true;
    return (R->data > root->data) && large(root, R->left) && large(root, R->right);
}

bool isBST(Node* root) {
    if (!root) return true;
    if (small(root, root->left) && large(root, root->right))
        return isBST(root->left) && isBST(root->right);
    else
        return false;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    if (isBST(root))
        cout << "This is a BST." << endl;
    else
        cout << "This is NOT a BST." << endl;

    return 0;
}
