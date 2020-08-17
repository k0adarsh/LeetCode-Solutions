class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {

        vector<int> ans;

        int n = mat.size();

        if(n == 0)
            return ans;

        int m = mat[0].size(),i,j;
        int low = 0, high = n - 1, lft = 0, rgt = m-1,dir = 0;

        while(low <= high && lft <= rgt)
        {
            if(dir == 0)
            {
                for(i=lft;i<=rgt;i++)
                    ans.push_back(mat[low][i]);
                dir = 1;
                low += 1;
            }
            else if(dir == 1)
            {
                for(i=low;i<=high;i++)
                    ans.push_back(mat[i][rgt]);
                dir = 2;
                rgt -= 1;
            }
            else if(dir == 2)
            {
                for(i=rgt;i>=lft;i--)
                    ans.push_back(mat[high][i]);
                dir = 3;
                high -= 1;
            }
            else if(dir == 3)
            {
                for(i=high;i>=low;i--)
                    ans.push_back(mat[i][lft]);
                dir = 0;
                lft += 1;
            }
        }
        return ans;
    }
};
