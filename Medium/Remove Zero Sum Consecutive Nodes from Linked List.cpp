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
    void calcPre(ListNode *head,vector<int> &preSum)
    {
        ListNode *ptr = head;
        if(head)
        {
            preSum.push_back(head->val);
            //cout<<"pushed "<<head->val<<endl;
            ptr = ptr->next;
            //cout<<preSum[preSum.size() - 1]<<endl;
        }
        while(ptr)
        {
            preSum.push_back(preSum[preSum.size() - 1] + ptr->val);
            //cout<<"pushed "<<ptr->val<<endl;
            ptr = ptr->next;
            //cout<<preSum[preSum.size() - 1]<<endl;
        }
        //cout<<"adarsh"<<endl;
    }
    ListNode* deleteList(ListNode *head,int m, int n)
    {
        int countt = 0;
        ListNode *ptr=head,*lst=NULL;
        while(countt < m-1)
        {
            countt+=1;
            lst = ptr;
            ptr = ptr->next;
        }
        while(countt < n)
        {
            countt+=1;
            //cout<<countt<<" ";
            //cout<<ptr->val<<endl;
            ptr = ptr->next;
        }
        if(lst == NULL)
            head = ptr;
        else
            lst->next = ptr;
        return head;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {

        ListNode *ptr = head;

        vector<int> preSum;

        if(head)
            calcPre(head,preSum);

        int i,n = preSum.size(),flag = 0,j;
        cout<<n<<endl;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(i==0)
                {
                    if(preSum[j] == 0)
                    {
                        flag = 1;
                        //cout<<"dlt "<<1<<" "<<j+1<<endl;
                        head = deleteList(head,1,j+1);
                        break;
                    }
                }
                else if(preSum[j] == preSum[i-1])
                {
                    flag = 1;
                    //cout<<"dlt "<<i+1<<" "<<j+1<<endl;
                    head = deleteList(head,i+1,j+1);
                    break;
                }
            }
            if(flag==1)
                break;
        }

        if(flag)
          head = removeZeroSumSublists(head);
        return head;
    }
};
