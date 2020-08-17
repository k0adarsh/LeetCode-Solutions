class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {

        int i,j,k,n = v.size(),m = v[0].size();
        map<int,int> x,y;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(v[i][j] == 0)
                {
                    x[i] = 1;
                    y[j] = 1;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(x[i] || y[j])
                    v[i][j] = 0;
            }
        }
    }
};
