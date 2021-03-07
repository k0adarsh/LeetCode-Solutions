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
    ListNode* removeElements(ListNode* head, int x) {

        ListNode *temp,*ptr;

        if(head == NULL)
            return NULL;

        while(head && head->val == x)
        {
            temp = head;
            head = head->next;
            delete temp;
        }

        if(head == NULL)
            return NULL;

        ptr = head;

        while(ptr->next)
        {
            temp = ptr->next;
            if(temp->val == x)
            {
                ptr->next = temp->next;
                delete temp;
            }
            else
                ptr = ptr->next;
        }
        return head;

    }

};
