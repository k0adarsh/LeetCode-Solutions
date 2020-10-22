class Solution {
public:
    int numSquares(int n) {

        int dp[n+1],i,j,sq;
        if(n<=3)
            return n;
        dp[0] = 0;
        for(i=1;i<=n;i++)
        {
            sq = sqrt(i);
            if(sq*sq == i)
            {
                dp[i] = 1;
                continue;
            }
            dp[i] = INT_MAX;
            for(j=1;j*j<=i;j++)
                dp[i] = min(dp[i],1+dp[i-j*j]);
        }
        return dp[n];
    }
};
