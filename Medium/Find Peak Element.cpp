class Solution {
public:
    int findPeakElement(vector<int>& v) {

        int low = 0,high = v.size() - 1,mid;
        if(v.size() == 1)
            return 0;
        while(low <= high)
        {
            //cout<<"searching in "<<low<<" "<<high<<endl;
            mid = low + (high-low)/2;
            if(mid==0 && v[mid] > v[mid + 1] )
                return mid;
            else if(mid==v.size()-1 && v[mid] > v[mid-1])
                return mid;
            else if(v[mid] > v[mid+1] && v[mid] > v[mid-1])
            {
                //cout<<"returning here "<<endl;
                return mid;
            }
            else if(v[mid] < v[mid+1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return mid;
    }
};
