
int getMaxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(getMaxDepth(root->left), getMaxDepth(root->right));
}
