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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *f;
        stack <TreeNode*> s;
        map<TreeNode*,int> m;
        vector <int> ans;
        s.push(root);
        while(!s.empty())
        {
            f = s.top();
            if(f==NULL)
                break;
            s.pop();
            if(m[f]==1)
            {
                 ans.push_back(f->val);
            }
            else
            {
                if(f->right)     s.push(f->right);
                if(f->left)      s.push(f->left);
                m[f] = 1;
                s.push(f);
            }
        }
        return ans;
    }
};
