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
class BSTIterator {
public:

    int mark;
    TreeNode *ptr;
    vector<int> v;

    void inOrder(TreeNode *root)
    {
        if(root == NULL)
            return;
        if(root->left)  inOrder(root->left);
        v.push_back(root->val);
        if(root->right) inOrder(root->right);
    }
    BSTIterator(TreeNode* root) {
        mark = 0;
        v.clear();
        inOrder(root);
    }

    /** @return the next smallest number */
    int next() {
        if(hasNext())
        {
            mark += 1;
            return v[mark-1];
        }
        return NULL;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       if(mark >= v.size())
           return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
