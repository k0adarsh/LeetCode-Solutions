class Solution {
public:
    int search(vector<int>& v, int x) {


        int low=0,mid,high = v.size() - 1,i,j;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(v[mid] == x)
                return mid;
            if(v[mid] >= v[low])
            {
                if(v[low] > x || v[mid] < x)
                    low = mid+1;
                else
                    high = mid-1;
            }
            else
            {
                if(v[mid] > x || v[high] < x)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return -1;
    }
};
