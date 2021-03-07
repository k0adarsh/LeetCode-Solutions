/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1 == NULL)
            return l2;
        if(l2==NULL)
            return l1;

        ListNode *temp;
        if(l1->val <= l2->val)
        {
            temp = new ListNode(l1->val);
            temp->next = mergeTwoLists(l1->next,l2);
        }
        else
        {
            temp = new ListNode(l2->val);
            temp->next = mergeTwoLists(l1,l2->next);
        }
        return temp;
    }
};
