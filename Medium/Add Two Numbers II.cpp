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
    ListNode* reverseList(ListNode *head)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0,s,r;

        if(l1==NULL || l2==NULL)
            return l1==NULL ? l2:l1;

        ListNode *head1 = reverseList(l1);
        ListNode *head2 = reverseList(l2);

        ListNode *head=NULL,*temp,*ptr;

        while(head1 && head2)
        {
            s = head1->val + head2->val + carry;
            r = s%10;
            carry = s/10;
            temp = new ListNode(r);

            if(head==NULL)
            {
                head = temp;
                ptr = head;
            }
            else
            {
                ptr->next = temp;
                ptr = temp;
            }
            head1=head1->next;
            head2=head2->next;
        }
        while(head1)
        {
            s = head1->val + carry;
            r = s%10;
            carry = s/10;
            temp = new ListNode(r);
            ptr->next = temp;
            ptr = temp;
            head1=head1->next;
        }
        while(head2)
        {
            s = head2->val + carry;
            r = s%10;
            carry = s/10;
            temp = new ListNode(r);
            ptr->next = temp;
            ptr = temp;
            head2=head2->next;
        }
        while(carry)
        {
            s = carry;
            r = s%10;
            carry = s/10;
            temp = new ListNode(r);
            ptr->next = temp;
            ptr = temp;
        }
        head = reverseList(head);
        return head;
    }
};


