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
class Solution {
public:
   
          TreeNode* build(vector<int> &postorder, int postlo, int posthigh,
                    vector<int> &inorder, int inlo, int inhigh) {
        if (postlo > posthigh)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[posthigh]);
        if (postlo == posthigh) {
            return root;
        }

        int i = inlo;
        while (i <= inhigh) {
            if (inorder[i] == postorder[posthigh])
                break;
            i++;
        }

        int leftcount = i - inlo;
        int rightcount = inhigh - i;

        root->left = build(postorder, 
                           postlo, 
                           postlo+leftcount-1,
                           inorder,
                           inlo,
                           i - 1);

        root->right = build(postorder,
                            postlo+leftcount,
                            posthigh - 1,
                            inorder,
                            i + 1,
                            inhigh);

        return root;
    }

     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        return build(postorder, 0, n - 1, inorder, 0, n - 1);
    }
    
};
