/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* makeBst(vector<int> v,int low,int high)
    {
        if(low <= high)
        {
            int mid;
            TreeNode *temp;
            mid = low + (high-low)/2;
            temp = new TreeNode(v[mid]);
            temp->left = makeBst(v,low,mid-1);
            temp->right = makeBst(v,mid+1,high);
            return temp;
        }
        return NULL;
    }
    TreeNode* sortedListToBST(ListNode* head) {

        vector<int> v;
        ListNode *ptr = head;
        while(ptr!=NULL)
        {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        return makeBst(v,0,v.size()-1);
    }
};
