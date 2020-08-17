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
    ListNode* reverse(ListNode *head)
    {
        ListNode *curr=head,*prev=NULL,*after;
        while(curr!=NULL)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(k == 0 || head == NULL || head->next == NULL)
            return head;

        int countt = 0,i;
        ListNode *curr=head,*prev=NULL,*after,*lst;

        while(curr!=NULL)
        {
            countt+=1;
            curr=curr->next;
        }

        k = k%countt;
        if(k==0)
            return head;
        head = reverse(head);

        curr = head;
        for(i=0;i<k;i++)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        lst = head;
        head = prev;
        lst->next = reverse(after);
        return head;
    }
};
