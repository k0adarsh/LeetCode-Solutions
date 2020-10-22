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
    vector<int> v;
    void inOrder(TreeNode *root)
    {
        if(root)
        {
            if(root->left)  inOrder(root->left);
            v.push_back(root->val);
            if(root->right) inOrder(root->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {

        inOrder(root);
        return v[k-1];
    }
};
