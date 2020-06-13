class Solution {
public:
    bool isPalindrome(string s)
    {
        int n = s.length(),i;
        for(i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {

        int i,j,n = s.length(),ans=1,len=0;
        string res;
        if(n==0)
            return res;
        int dp[n][n];
        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<n;j++)
            {
                if(j<i)
                    dp[i][j] = 0;
                else if(i==j)
                    dp[i][j] = 1;
                else
                {
                    if(j==i+1)
                    {
                        if(s[i]==s[j])
                        {
                            dp[i][j] = 1;
                            len = 2;
                            ans = max(ans,len);
                            if(ans == len)
                            {
                                res = s.substr(i,j-i+1);
                            }
                        }
                        else
                            dp[i][j] = 0;
                    }
                    else if(s[i]==s[j] && dp[i+1][j-1])
                    {
                        len = j - i + 1;
                        ans = max(ans,len);
                        if(ans == len)
                        {
                            res = s.substr(i,j-i+1);
                        }
                        dp[i][j] = 1;
                    }
                    else
                        dp[i][j] = 0;
                }
            }
        }

        if(ans==1)
        {
            res += s[0];
        }
        return res;
    }
};
