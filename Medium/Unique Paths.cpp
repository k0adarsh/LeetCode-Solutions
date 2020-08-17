class Solution {
public:
int uniquePaths(int m, int n)
{
    int i,j;
    int dp[n][m];
    dp[0][0] = 1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i==0 && j==0)
                continue;
            if(i==0 || j==0)
            {
                if(i==0)
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
            else
               dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}
};
