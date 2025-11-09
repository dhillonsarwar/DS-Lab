#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


    bool isValidBS(TreeNode* root, long min, long max) {
        if (!root)
            return true;
        if (root->val >= max || root->val <= min)
            return false;
        return isValidBS(root->left, min, root->val) &&
               isValidBS(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBS(root, LONG_MIN, LONG_MAX);
 =}
int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    if (isValidBST(root))
        cout << "This is a BST." << endl;
    else
        cout << "This is NOT a BST." << endl;

    return 0;
}
