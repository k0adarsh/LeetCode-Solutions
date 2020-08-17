class Solution {
public:

    int xis[4] = {1,0,0,-1};
    int yix[4] = {0,1,-1,0};

    bool checkPre(vector<vector<char>>& board, string word,int i,int j,string &temp,int k,                                                                                              vector<vector<int>> &vis)
    {
        int p,x,y;
        int n = board.size();
        int m = board[0].size();

        if(temp == word)
            return true;

        if(board[i][j] == word[k])
        {
            vis[i][j] = 1;
            for(p=0;p<4;p++)
            {
               x = i + xis[p];
               y = j + yix[p];
               if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == 1)
                   continue;
               if(board[x][y] == word[k+1])
               {
                   temp += word[k+1];
                   cout<<temp<<" "<<x<<" "<<y<<endl;
                   if(checkPre(board,word,x,y,temp,k+1,vis))
                       return true;
                   vis[x][y] = 0;
                   temp.pop_back();
               }
            }
        }
        //temp.pop_back();
        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int i,j;
        int n = board.size();
        int m = board[0].size();

       vector<vector<int>> vis(n,vector<int>(m,0));

       string temp;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
               temp.clear();
               temp += board[i][j];
               if(board[i][j] == word[0])
                   if(checkPre(board,word,i,j,temp,0,vis))
                       return true;
            }
        }

        return false;
    }
};
