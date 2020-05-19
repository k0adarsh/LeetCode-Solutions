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

    bool helperFunction(TreeNode *root, int curr, int sum){

        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL)
        {
            if(curr+root->val==sum)
                return true;
            return false;
        }
        return helperFunction(root->left,curr+root->val,sum) ||
            helperFunction(root->right,curr+root->val,sum);

    }
    bool hasPathSum(TreeNode* root, int sum) {
       return helperFunction(root,0,sum);
    }
};
