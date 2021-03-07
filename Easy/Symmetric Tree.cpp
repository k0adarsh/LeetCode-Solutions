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
    bool helperFunc(TreeNode* root, TreeNode* lft, TreeNode* rgt)
    {
        if(!lft && !rgt)
            return true;
        if(!lft || !rgt)
            return false;

        if(lft->val == rgt->val)
           return helperFunc(root,lft->left,rgt->right) && helperFunc(root,lft->right,rgt->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;
        return helperFunc(root,root->left,root->right);
    }
};
