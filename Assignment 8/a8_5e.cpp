/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution { public:
TreeNode* build(vector<int> preorder,int prelo,int prehigh, vector<int> inorder,int inlo,int inhigh){
    if(prelo>prehigh)return nullptr;
    TreeNode *root=new TreeNode(preorder[prelo]);
    if(prelo==prehigh){return root;}
    int i=0;
    while(inlo<inhigh){
        if(inorder[i]==preorder[prelo]) break;
        i++;
    }
    int leftcount=i-inlo;
    int rightcount=inhigh-i;
    root->left=build(preorder,prelo+1,prelo+leftcount,inorder,inlo,i-1);
root->right=build(preorder,prelo+leftcount+1,prehigh,inorder,i+1,inhigh);
return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return build(preorder,0,n-1,inorder,0,n-1);
    }
};
