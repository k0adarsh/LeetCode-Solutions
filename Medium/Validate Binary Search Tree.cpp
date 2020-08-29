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
    bool isBst(TreeNode *root, long minn,long maxx)
    {
        if(root==NULL)
            return true;
        if(root->val >= maxx || root->val <= minn)
            return false;
        return (isBst(root->left,minn,root->val) && isBst(root->right,root->val,maxx));
    }
    bool isValidBST(TreeNode* root) {

        return isBst(root,LONG_MIN,LONG_MAX);
    }
};
