class Solution {
public:
    int numDecodings(string s) {
    if(s[0]=='0')
        return 0;

    int i,n = s.length(),res;
    if(n==1)
        return 1;

    vector <int> dp;
    dp.push_back(1);

    for(i=1;i<n;i++)
    {
        res = 10*(s[i-1] - '0') + (s[i] - '0');
        if(s[i]=='0')
        {

            if(res > 26 || res == 0)
                return 0;
            else
            {
                if(i==1)
                    dp.push_back(1);
                else
                    dp.push_back(dp[i-2]);
            }
        }
        else if(s[i-1]=='0')
        {
            dp.push_back(dp[i-1]);
        }
        else
        {
            if(res > 26)
                dp.push_back(dp[i-1]);
            else
            {
                if(i==1)
                    dp.push_back(2);
                else
                    dp.push_back(dp[i-1] + dp[i-2]);
            }
        }
    }
    return dp[n-1];

    }
};
