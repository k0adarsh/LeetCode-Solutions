int change(int t, vector<int>& v) {

        int n = v.size(),i,j;
        int dp[n+1][t+1];

        for(i=0;i<=n;i++)
        {
            for(j=0;j<=t;j++)
            {
                if(i==0 || j==0)
                {
                   if(i==0)
                    dp[i][j] = 0;
                   if(j==0)
                    dp[i][j] = 1;
                }
                else
                {
                    if(j < v[i-1])
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-v[i-1]];
                }
            }
        }
        return dp[n][t];
    }
};
