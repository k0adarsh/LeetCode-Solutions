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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *ptr = head,*temp;
        int i,countt=0;
        if(head==NULL || head->next==NULL)
            return NULL;
        while(ptr!=NULL)
        {
            ptr = ptr->next;
            countt+=1;
        }
        countt = countt-n;
        ptr = head;
        if(countt==0)
        {
            temp = head;
            head = temp->next;
            delete temp;
            return head;
        }
        for(i=1;i<=countt-1;i++)
            ptr=ptr->next;

        temp  = ptr->next;
        ptr->next = temp->next;
        delete temp;
        return head;
    }
};
