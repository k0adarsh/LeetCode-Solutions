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

    TreeNode* treeBuilder(vector<int>& inorder, vector<int>& postorder,int low, int high,int &mark)
    {
        if(low > high)
            return NULL;

        int ind = low;
        while(inorder[ind] != postorder[mark])
            ind += 1;
        mark-=1;
        TreeNode *temp = new TreeNode(inorder[ind]);

        temp->right = treeBuilder(inorder,postorder,ind+1,high,mark);
        temp->left = treeBuilder(inorder,postorder,low,ind-1,mark);

        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size(),mark;
        mark = n - 1;
        return treeBuilder(inorder,postorder,0,n-1,mark);
    }
};
