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
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        TreeNode* f;
        q.push(root);
        q.push(NULL);

        vector<int> res;
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        while(!q.empty())
        {
            f = q.front();
            q.pop();
            if(f==NULL)
            {
                if(!q.empty())
                {
                    ans.push_back(res);
                    res.clear();
                    q.push(NULL);
                }
            }
            else
            {
                res.push_back(f->val);
                if(f->left)     q.push(f->left);
                if(f->right)    q.push(f->right);
            }
        }
        ans.push_back(res);
        return ans;
    }
};
