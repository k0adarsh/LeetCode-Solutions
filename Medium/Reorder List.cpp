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
    ListNode* reverseHalf(ListNode* head)
    {
        ListNode *prev=NULL,*curr=head,*after;
        while(curr!=NULL)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }
    void reorderList(ListNode* head) {

    ListNode *slow,*fast,*lst,*ptr,*temp,*mid;
    if(head == NULL || head->next == NULL || head->next->next == NULL)
         return ;

    slow = head;
    fast = head;
    while(fast->next !=NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    mid = slow;
    mid ->next = reverseHalf(mid->next);

    ptr = head;
    while(ptr!=mid)
    {
        temp = ptr->next;
        lst = mid->next;
        mid->next = lst->next;
        ptr->next = lst;
        lst->next = temp;
        ptr = temp;
    }
}
};


