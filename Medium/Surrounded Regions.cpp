class Solution {
public:
    map<pair<int,int>,int> vis;
    void dfs(vector<vector<char>> &v, int i, int j)
    {
        int k,x,y;
        int iShift[4] = {0,1,-1,0};
        int jShift[4] = {1,0,0,-1};

        vis[make_pair(i,j)] = 1;

        for(k=0;k<4;k++)
        {
            x = i + iShift[k];
            y = j + jShift[k];
            if(x<0 || y<0 || x>=v.size() || y>=v[0].size())
                continue;
            else if(v[x][y] == 'O' && vis[make_pair(x,y)] == 0)
                dfs(v,x,y);
        }
    }
    void solve(vector<vector<char>>& v) {

        if(v.size() == 0)
            return ;
        int i,j,n=v.size(),m=v[0].size();
        vis.clear();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(v[i][j] == 'O')
                        dfs(v,i,j);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(v[i][j]=='O' && vis[make_pair(i,j)] == 0)
                    v[i][j] = 'X';
            }
        }
    }
};
