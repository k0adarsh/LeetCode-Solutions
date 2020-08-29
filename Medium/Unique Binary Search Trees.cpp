class Solution {
public:
    int numTrees(int n) {

        int i,j;
        vector<int> dp(n+1,0);
        dp[0] = 1;;
        for(i=1;i<=n;i++)
        {
            if(i==1)
                dp[i] = 1;
            else if(i==2)
                dp[i] = 2;
            else
            {
                for(j=1;j<=i;j++)
                {
                    //cout<<dp[j-1]<<" "<<dp[n-j]<<" = ";
                    dp[i] += (dp[j-1] * dp[i-j]);
                    //cout<<dp[i]<<endl;
                }
            }
        }
        return dp[n];
    }
};
