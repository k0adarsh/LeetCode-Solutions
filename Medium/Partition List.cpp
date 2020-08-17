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
    ListNode* partition(ListNode* head, int x) {

        ListNode *lst=NULL,*st=NULL,*temp,*ptr;
        ptr = head;
        if(head==NULL || head->next==NULL)
            return head;
        while(ptr!= NULL && ptr->val < x)
        {
            lst = ptr;
            ptr = ptr->next;
        }
        st = ptr;
        if(ptr==NULL)
            return head;
        while(ptr->next!=NULL)
        {
            if(ptr->next->val < x )
            {
                temp = ptr->next;
                ptr->next = temp->next;
                if(lst == NULL)
                {
                    head = temp;
                    head->next = st;
                    lst = head;
                    continue;
                }
                lst->next = temp;
                temp->next = st;
                lst = lst->next;
            }
            else
                ptr = ptr->next;
        }
       return head;
    }
};
