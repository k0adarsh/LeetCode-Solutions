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
    int numComponents(ListNode* head, vector<int>& v) {

        int i;
        map<int,int> m;
        for(i=0;i<v.size();i++)
            m[v[i]] = 1;

        if(head==NULL)
            return 0;

        int flag = 0,countt = 0;
        ListNode *ptr = head;
        while(ptr!=NULL)
        {
            if(m[ptr->val] == 1)
            {
                if(flag == 0)
                {
                    countt += 1;
                    flag = 1;
                }
            }
            else
                flag = 0;
            ptr = ptr->next;
        }
        return countt;
    }
};
