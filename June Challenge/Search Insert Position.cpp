int searchInsert(vector<int>& v, int t) {

        int n = v.size();
        int low=0,high=n-1,mid;
        while(low <= high)
        {
            mid = low + (high - low)/2;
            if(v[mid]==t)
                return mid;
            if(v[mid] > t)
                high = mid-1;
            else
                low = mid + 1;
        }
        return low;
    }
