int partition(vector<int> &v, int start, int endd)
    {
        int pivot = v[endd];
        int pIndex = start;
        for(int i=start;i<endd;i++)
        {
            if(v[i] <= pivot)
            {
                swap(v[i],v[pIndex]);
                pIndex+=1;
            }
        }
        swap(v[pIndex],v[endd]);
        return pIndex;
    }
    void qSort(vector<int> &v,int start,int endd)
    {
        if(start < endd)
        {
            int pIndex = partition(v,start,endd);

            qSort(v,start,pIndex-1);
            qSort(v,pIndex+1,endd);
        }
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        qSort(nums,0,n-1);
    }
