
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

int leafsum(Node* root){
if(!root)return 0;
if(!root->left&&!root->right)return root->val;
return leafsum(root->left) + leafsum(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    cout << "Sum of all leaf nodes: " << leafsum(root) << endl;
    return 0;
}
