class Solution {
public:
    bool canJump(vector<int>& v) {

        int n = v.size(),i;
        int dp[n];

        dp[0] = v[0];
        if(dp[0] <= 0 && n > 1)
            return false;

        for(i=1;i<n-1;i++)
        {
            dp[i] = max(dp[i-1],i+v[i]);
            if(dp[i]<=i)
                return false;
        }
        return true;
    }
};
