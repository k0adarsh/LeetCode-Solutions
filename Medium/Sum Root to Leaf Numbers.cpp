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
    void calcSum(TreeNode*root,string s,int &ans)
    {
        if(root==NULL)
            return;
        s += (char)(root->val + 48);
        if(root->left == NULL && root->right == NULL)
        {
            //cout<<s<<endl;
            ans += stoi(s);
            return ;
        }

        if(root->left)  calcSum(root->left,s,ans);
        if(root->right) calcSum(root->right,s,ans);
    }
    int sumNumbers(TreeNode* root) {

        int ans = 0;
        string s;
        calcSum(root,s,ans);
        return ans;
    }
};
