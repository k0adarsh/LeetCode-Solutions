class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& v) {

        int i,ans,j;
        int dp[n+1];
        int countt[v.size()];

        for(i=0;i<v.size();i++)
            countt[i] = 1;

        dp[0] = 1;
        dp[1] = 1;
        cout<<1<<" ";
        for(i=2;i<=n;i++)
        {
            dp[i] = INT_MAX;

            for(j=0;j<v.size();j++)
                dp[i] = min(dp[i],dp[countt[j]] * v[j]);

            for(j=0;j<v.size();j++)
            {
                if(dp[i] == dp[countt[j]] * v[j])
                    countt[j]+=1;
            }
            //cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};
