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

    TreeNode* makeTree(vector<int> &preorder, vector<int> &inorder,int low,int high, int &mark)
    {
        if(low > high)
            return NULL;
        int i;
        TreeNode *temp;
        //cout<<"making node for "<<preorder[mark]<<" low = "<<low<<" high = "<<high<<endl;
        temp = new TreeNode(preorder[mark]);
        for(i=low;i<=high;i++)
        {
            if(inorder[i] == preorder[mark])
            {
                 mark+=1;
                 break;
            }
        }
        //cout<<"found at "<<i<<" mark set to "<<mark<<endl;
        int index = i;
        temp->left = makeTree(preorder,inorder,low,index-1,mark);
        temp->right = makeTree(preorder,inorder,index+1,high,mark);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int mark=0,low=0,high = preorder.size()- 1;
        return makeTree(preorder,inorder,low,high,mark);
    }
};
