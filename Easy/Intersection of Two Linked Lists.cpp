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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == headB)
            return headA;

        if(!headA || !headB)
            return NULL;
        int countA = 0, countB = 0,i;

        ListNode* temp;
        temp = headA;

        while(temp!=0)
        {
            countA+=1;
            temp = temp->next;
        }

        temp = headB;
        while(temp!=0)
        {
            countB+=1;
            temp = temp->next;
        }

        if(countA < countB)
        {
            for(i=0;i<countB-countA;i++)
                headB = headB->next;
        }
        else
        {
            for(i=0;i<countA-countB;i++)
                headA = headA->next;
        }
        cout<<countA<<" "<<countB<<endl;
        cout<<headA->val<<endl;
        cout<<headB->val<<endl;
        while(headA && headB)
        {
            if(headA == headB)
                return headA;

            headA = headA->next;
            headB= headB->next;
        }
        return NULL;
    }
};
