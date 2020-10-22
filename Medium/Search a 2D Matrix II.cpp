class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {

        if(v.size()==0 || v[0].size() == 0)
            return false;
        int i = 0,j=v[0].size()-1;
        while(i < v.size() && j >= 0)
        {
            if(v[i][j] == t)
                return true;
            else if(v[i][j] < t)
                i+=1;
            else
                j-=1;
        }
        return false;
    }
};
