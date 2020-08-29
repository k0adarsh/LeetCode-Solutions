class Solution {
public:
    void trim(string &s)
    {
        int i,lst = -1;
        for(i=0;i<s.length();i++)
        {
            if(s[i] != ' ')
                break;
        }
        s = s.substr(i,s.length() - i);
        for(i=0;i<s.length();i++)
        {
            if(s[i]==' ' && lst == -1)
                lst = i;
            else if(s[i] != ' ')
                lst = -1;
        }
        s = s.substr(0,lst);
    }
    string reverseWords(string s) {

        int i;
        vector<string> ans;
        string temp;
        trim(s);

        for(i=0;i<s.length();i++)
        {
            if(s[i]==' ' && temp.length() > 0)
            {
                ans.push_back(temp);
                temp.clear();
            }
            else if(s[i]!=' ')
                temp+=s[i];
        }

        ans.push_back(temp);
        reverse(ans.begin(),ans.end());
        s.clear();
        for(i=0;i<ans.size();i++)
        {
            s += ans[i];
            if(i<ans.size()-1)
                s += ' ';
        }
        return s;
    }
};
