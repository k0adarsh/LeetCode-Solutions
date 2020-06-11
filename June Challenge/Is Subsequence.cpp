bool checkSub(string s, string t, int i, int j)
    {
        if(j==t.length())
        {
            if(i==s.length())
                return true;
            return false;
        }
        if(s[i]==t[j])
            return checkSub(s,t,i+1,j+1);
        return checkSub(s,t,i,j+1);
    }
    bool isSubsequence(string s, string t) {

       return checkSub(s,t,0,0);
    }
