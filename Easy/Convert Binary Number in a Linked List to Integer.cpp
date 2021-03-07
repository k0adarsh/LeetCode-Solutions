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
class Solution {
public:
    int helperFun(ListNode* node, int &ind)
    {
        int res = 0;
        if(node == NULL)
            return 0;
        if(node->next == NULL)
        {
             res = (node->val);
             ind += 1;
             return res;
        }
        int nextSum = helperFun(node->next, ind);
        res = (node->val) * pow(2,ind) + nextSum;

        ind += 1;
        return  res;
    }
    int getDecimalValue(ListNode* head) {

        int ind = 0;
        int res = helperFun(head,ind);
        return res;
    }
};
