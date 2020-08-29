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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        TreeNode* f;
        q.push(root);
        q.push(NULL);

        int flag = 0;
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
                    if(flag==1)
                        reverse(res.begin(),res.end());
                    flag = 1 - flag;
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
        if(flag==1)
            reverse(res.begin(),res.end());
        ans.push_back(res);
        return ans;
    }
};
