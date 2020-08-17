class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {


        vector<vector<int>> ans(n,vector<int>(n,0));


        if(n == 0)
            return ans;

        int i,j;
        int low = 0, high = n - 1, lft = 0,rgt = n-1,dir = 0,countt = 1;

        while(low <= high && lft <= rgt)
        {
            if(dir == 0)
            {
                for(i=lft;i<=rgt;i++)
                {
                    ans[low][i] = countt;
                    countt+=1;
                }
                dir = 1;
                low += 1;
            }
            else if(dir == 1)
            {
                for(i=low;i<=high;i++)
                 {
                    ans[i][rgt] = countt;
                    countt+=1;
                }
                dir = 2;
                rgt -= 1;
            }
            else if(dir == 2)
            {
                for(i=rgt;i>=lft;i--)
                {
                   ans[high][i] = countt;
                   countt+=1;
                }
                dir = 3;
                high -= 1;
            }
            else if(dir == 3)
            {
                for(i=high;i>=low;i--)
                {
                    ans[i][lft] = countt;
                    countt+=1;
                }
                dir = 0;
                lft += 1;
            }
        }
        return ans;
    }
};
