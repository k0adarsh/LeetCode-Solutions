class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {

        if(v.size() == 0 || v[0].size()==0)
            return false;
        int low = 0,high = v.size() - 1,m = v[0].size()-1,ans=-1,mid;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(v[mid][0] > t )
                high = mid - 1;
            else if(v[mid][m] < t)
                low = mid + 1;
            else
            {
                ans = mid;
                break;
            }
        }
        if(ans==-1)
            return false;

        low = 0;high = m;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(v[ans][mid] == t)
                return true;
            else if(v[ans][mid] > t)
                high = mid -1;
            else
                low = mid + 1;
        }
        return false;
    }
};
