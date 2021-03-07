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

    void findMin(TreeNode *root,int lev,int &ans)
    {
        if(root->left==NULL && root->right==NULL)
            ans = min(ans,lev);
        else
        {
            if(root->left)  findMin(root->left,lev+1,ans);
            if(root->right) findMin(root->right,lev+1,ans);
        }
    }
    int minDepth(TreeNode *root) {

        int ans=INT_MAX;
        if(root==NULL)
            return 0;
        findMin(root,1,ans);
        return ans;
    }
};
