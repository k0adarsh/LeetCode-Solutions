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

    ListNode* addList(ListNode* ptr1,ListNode *ptr2, int carry)
    {
        int summ = 0;
        if(ptr1)
            summ+=ptr1->val;
        if(ptr2)
            summ+=ptr2->val;

        summ += carry;
        carry = summ/10;
        summ = summ%10;

        ListNode *temp = new ListNode(summ);

        if(ptr1==NULL && ptr2==NULL && summ == 0)
            return NULL;
        if(ptr1 == NULL && ptr2 == NULL)
            temp->next = NULL;

        else if(ptr1 == NULL)
            temp->next = addList(NULL,ptr2->next,carry);

        else if(ptr2 == NULL)
            temp->next = addList(ptr1->next,NULL,carry);

        else
            temp->next = addList(ptr1->next,ptr2->next,carry);

        return temp;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        return addList(l1,l2,0);
    }
};
