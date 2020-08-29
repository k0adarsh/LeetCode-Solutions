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
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        int countt = 0;
        ListNode *ptr=NULL,*lst=NULL,*prev,*after,*curr;
        while(countt != m - 1)
        {
            if(ptr==NULL)
                ptr = head;
            else
                ptr=ptr->next;
            countt+=1;
        }
        if(ptr!=NULL)
        {
             lst = ptr;
             ptr=ptr->next;
        }
        else
            ptr = head;

        prev = NULL;
        curr = ptr;
        while(countt!=n)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;

            countt+=1;
        }
        if(lst)   lst->next = prev;
        else      head = prev;
        ptr->next = curr;
        return head;
    }
};
