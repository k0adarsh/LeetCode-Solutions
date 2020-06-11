vector<int> w;
    int sum;

    Solution(vector<int>& v) {
        sum = 0;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
            w.push_back(sum);
        }
    }

    int pickIndex() {
        int wt = rand() % sum;
        return bSearch(wt+1);
    }

    int bSearch(int x)
    {
        int low = 0, high = w.size()-1,mid;
        while(low < high)
        {
            mid = low + (high-low)/2;
            if(w[mid] < x)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
