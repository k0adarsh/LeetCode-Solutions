class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int i,j,n = v.size(),ans = INT_MAX;
    int dp[n][n+1];

    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(i==0)
            {
                dp[i][j] = v[i][j];
                continue;
            }
            if(j==0)
                dp[i][j] = dp[i-1][j] + v[i][j];
            else
            {
                if(j==i)
                    dp[i][j] = dp[i-1][j-1] + v[i][j];
                else
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + v[i][j];
            }
        }
    }
    for(i=0;i<n;i++)
        ans = min(ans,dp[n-1][i]);
    return ans;

    }
};
