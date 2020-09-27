class Solution {
public:
    int findMin(vector<int>& v) {

        int mid,high=v.size()-1,low=0,ans = INT_MAX;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            ans = min(ans,v[mid]);
            if(v[mid] > v[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
        ans = min(ans,v[mid]);
        return ans;
    }
};
