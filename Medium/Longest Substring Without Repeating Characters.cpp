int lengthOfLongestSubstring(string s) {

        int i=0,j=0,ans=1,n=s.length(),len;
        if(n==0)
            return 0;
        map<char,int> m;
        m[s[0]] = 1;
        while(i<n-1 && j<n-1)
        {
            if(m[s[j+1]]==0)
            {
                m[s[j+1]] = 1;
                j+=1;
                len = j-i+1;
                ans = max(ans,len);
            }
            else
            {
                m[s[i]] = 0;
                i+=1;
            }
        }
        return ans;
    }
