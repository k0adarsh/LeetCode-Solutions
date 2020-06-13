class Solution {
public:
    vector<int> searchRange(vector<int>& v, int x) {

        int low = 0,high = v.size()-1,mid;
        vector<int> ans;

        ans.push_back(-1);
        ans.push_back(-1);
        if(v.size() == 0)
            return ans;
        while(low < high)
        {
            mid = low + (high-low)/2;
            if(x <= v[mid])
                high = mid;
            else
                low = mid+1;
        }
        //cout<<high<<endl;
        if(v[high] == x)
            ans[0] = high ;

        low=0,high = v.size() - 1;
        while(low < high)
        {
            mid = low + ceil((high-low)/(double)2);
            if(x >= v[mid])
                low = mid;
            else
                high = mid-1;

        }
        if(v[low] == x)
            ans[1] = low;

        return ans;
    }
};
