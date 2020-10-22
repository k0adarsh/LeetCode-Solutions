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
    bool searchNode(TreeNode* root, TreeNode *x)
    {
        if(root==NULL)
            return false;
        if(root == x)
            return true;
        return (searchNode(root->left,x) || searchNode(root->right,x));
    }
    TreeNode* findLca(TreeNode* root, TreeNode* p, TreeNode *q)
    {
        TreeNode *lft=NULL,*rgt=NULL;
        if(root==NULL)
            return NULL;
        if(root==p ||root==q)
            return root;

        lft = findLca(root->left,p,q);
        rgt = findLca(root->right,p,q);

        if(lft && rgt)
            return root;
        if(lft)
            return lft;
        return rgt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==NULL)
            return NULL;
        if(!(searchNode(root,p) || !(searchNode(root,q))))
            return NULL;
        return findLca(root,p,q);
    }
};
