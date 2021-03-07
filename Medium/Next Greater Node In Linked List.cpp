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
    vector<int> nextLargerNodes(ListNode* head) {

        int i,j,n;
        vector<int> v;
        stack<int> s;
        ListNode *ptr = head;
        while(ptr!=NULL)
        {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        n = v.size();
        vector<int> ans(n,0);
        for(i=n-1;i>=0;i--)
        {
            //cout<<v[i]<<" ";
            if(s.empty())
            {
                s.push(v[i]);
                ans[i] = 0;
            }
            else
            {
                if(s.top() > v[i])
                {
                    ans[i] = s.top();
                    s.push(v[i]);
                }
                else
                {
                    while(!s.empty() && s.top() <= v[i])
                        s.pop();
                    if(s.empty())
                    {
                        ans[i] = 0;
                        s.push(v[i]);
                    }
                    else
                    {
                        ans[i] = s.top();
                        s.push(v[i]);
                    }
                }
            }
            //cout<<"answer pushed is "<<ans[i]<<endl;
        }
        return ans;
    }
};
