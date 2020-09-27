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
    void rightView(TreeNode *root,vector<int> &ans,int lev,int &maxx)
    {
        if(root==NULL)
            return ;
        if(lev > maxx)
        {
            ans.push_back(root->val);
            maxx = lev;
        }
        if(root->right) rightView(root->right,ans,lev+1,maxx);
        if(root->left)  rightView(root->left,ans,lev+1,maxx);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxx = -1;
        rightView(root,ans,0,maxx);
        return ans;
    }
};
