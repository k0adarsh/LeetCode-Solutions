class Solution {
public:
    int lengthOfLIS(vector<int>& v) {

        int i,j,n=v.size();
        if(n<=1)
            return n;

        int lis[n],ans=1;

        for(i=0;i<n;i++)
            lis[i] = 1;

        for(j=1;j<n;j++)
        {
            for(i=0;i<j;i++)
            {
                if(v[j]>v[i])
                {
                    lis[j] = max(lis[j],lis[i]+1);
                    ans = max(ans,lis[j]);
                }
            }
        }
        return ans;
    }
};
