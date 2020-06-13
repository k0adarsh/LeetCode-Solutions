class Solution {
public:
    vector<string> ans;
    void doParen(string s,int lft,int rgt)
    {
       if(lft==0 && rgt==0)
       {
           ans.push_back(s);
           return ;
       }
       if(lft > 0)
           doParen(s+'(',lft-1,rgt+1);
       if(rgt > 0)
           doParen(s+')',lft,rgt-1);
    }
    vector<string> generateParenthesis(int n) {

        string s;
        ans.clear();
        doParen(s,n,0);
        return ans;
    }
};
