class Solution {
public:
    bool search(vector<int>& v, int t) {

        int low = 0,high = v.size() - 1,mid;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(v[mid]==t)
                return true;
            if(v[mid] == v[low] && v[mid] == v[high])
            {
                low += 1;
                high -= 1;
            }
            else if(v[mid] >= v[low])
            {
                if(v[low] > t  || v[mid] < t)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
            {
                if(v[mid] > t || v[high] < t)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return false;
    }
};
