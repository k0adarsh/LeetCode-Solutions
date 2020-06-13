class Solution {
public:
    bool okRow(vector<vector<char>>& v, int i,int j)
    {
        int k;
        char x = v[i][j];
        for(k=0;k<9;k++)
        {
            if(k!= j && v[i][k] == x)
                return false;
        }
        return true;
    }
    bool okCol(vector<vector<char>>& v, int i,int j)
    {
        int k;
        char x = v[i][j];
        for(k=0;k<9;k++)
        {
            if(k!= i && v[k][j] == x)
                return false;
        }
        return true;
    }
    bool okBox(vector<vector<char>>& v, int i,int j)
    {
        int k = 3*(i/3),l = 3*(j/3),p,q;
        char x = v[i][j];
        for(p=k;p<k+3;p++)
        {
            for(q=l;q<l+3;q++)
            {
                if(p==i && q==j)
                    continue;
                else if(v[p][q] == x)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        int i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(okRow(board,i,j) && okCol(board,i,j) && okBox(board,i,j))
                        continue;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
