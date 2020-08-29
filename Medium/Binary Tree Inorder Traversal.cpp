/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector <int> ans;
        TreeNode *f;
        map<TreeNode*,int> m;
        if(root == NULL)
            return ans;
        s.push(root);
        while(!s.empty())
        {
            f = s.top();
            s.pop();
            if(m[f] == 1)
                ans.push_back(f->val);
            else
            {
                if(f->right)       s.push(f->right);
                m[f] = 1;
                s.push(f);
                if(f->left)     s.push(f->left);
            }
        }
        return ans;
    }
};
