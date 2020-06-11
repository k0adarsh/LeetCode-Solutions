TreeNode* invertTree(TreeNode* root) {

        TreeNode *temp;
        if(root==NULL)
            return NULL;
        temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }
