class Solution {
public:

    map<char,string> m;
    vector<string> ans;

    void findComb(string dig, string s, int i)
    {
        if(i == dig.length())
        {
            if(s.length() != 0)
                ans.push_back(s);
            return ;
        }

        int j;
        char x = dig[i];

        for(j = 0; j < m[x].length(); j++)
        {
             s +=  m[x][j];
             findComb(dig,s,i+1);

             s.pop_back();
        }
    }
    vector<string> letterCombinations(string dig) {

        string s;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        findComb(dig,s,0);

        return ans;
    }
};
