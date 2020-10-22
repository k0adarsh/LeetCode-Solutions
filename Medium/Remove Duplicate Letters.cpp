class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack <char> st;
    string ans;
    int i;
    map <char,int> m,vis;
    for(i=0;i<s.length();i++)
    {
        m[s[i]] += 1;
    }
    st.push(s[0]);
    m[s[0]]-=1;
    vis[s[0]] = 1;
    for(i=1;i<s.length();i++)
    {
        if(vis[s[i]] == 0)
        {
            p : if(!st.empty() && st.top() > s[i] && m[st.top()] > 0)
            {
                vis[st.top()] = 0;
                st.pop();
                goto p;
            }
            st.push(s[i]);
            vis[s[i]] = 1;
        }
        m[s[i]] -= 1;
    }
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;

    }
};
