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

    TreeNode* convertBST(vector<int> &v, int low, int high)
    {
        if(low > high)
            return NULL;
        int mid = low + (high-low)/2;
        TreeNode *ptr = new TreeNode(v[mid]);
        ptr->left = convertBST(v,low,mid-1);
        ptr->right = convertBST(v,mid+1,high);

        return ptr;
    }
    TreeNode* sortedArrayToBST(vector<int>& v) {

        int n = v.size();
        return convertBST(v,0,n-1);
    }
};
