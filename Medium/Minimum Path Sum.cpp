class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
    int i,j,n = v.size(),m = v[0].size();
    int dp[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i==0 && j==0)
                dp[0][0] = v[0][0];
            else if(i==0 || j==0)
            {
                if(i==0)
                    dp[i][j] = dp[i][j-1] + v[i][j];
                else
                    dp[i][j] = dp[i-1][j] + v[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + v[i][j];
            }
        }
    }
    return dp[n-1][m-1];

    }
};
