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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head==NULL || head->next==NULL)
            return head;

        ListNode *ptr = head,*temp = NULL, *lst = NULL , *st = NULL;

        ptr = head;
        while(ptr->next!=NULL)
        {
            if(ptr->val == ptr->next->val)
            {
                st = ptr;
                temp = ptr->next;
                ptr->next = temp->next;
                delete temp;
            }
            else
            {
                if(st!=NULL)
                {
                    if(lst==NULL)
                        head = st->next;
                    else
                        lst->next = st->next;
                    ptr = ptr->next;
                    temp = st;
                    st = NULL;
                    delete temp;
                }
                else
                {
                    lst = ptr;
                    ptr = ptr->next;
                }
            }



        }
        if(st!=NULL)
        {
            if(lst == NULL)
                head = st->next;
            else
                lst->next = st->next;
            delete st;
        }
        return head;
    }
};
