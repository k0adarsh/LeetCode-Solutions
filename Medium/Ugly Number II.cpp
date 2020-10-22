class Solution {
public:
    int nthUglyNumber(int n) {

        int i=1,j=1,k=1,it;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for(it=2;it<=n;it++)
        {
            dp[it] = min(2*dp[i],min(3*dp[j],5*dp[k]));

            if(dp[it] == dp[i]*2)
                i+=1;
            if(dp[it] == dp[j]*3)
                j+=1;
            if(dp[it] == dp[k]*5)
                k+=1;
            cout<<dp[it]<<" ";
        }
        return dp[n];
    }
};
