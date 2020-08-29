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
    void calcPath(TreeNode *root, vector<int> temp, vector<vector<int>> &ans, int curr, int sum)
    {
        if(root == NULL)
            return;
        curr += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            if(curr == sum)
                ans.push_back(temp);
        }
        if(root->left)  calcPath(root->left,temp,ans,curr,sum);
        if(root->right)  calcPath(root->right,temp,ans,curr,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        int curr = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        calcPath(root,temp,ans,curr,sum);
        return ans;
    }
};
