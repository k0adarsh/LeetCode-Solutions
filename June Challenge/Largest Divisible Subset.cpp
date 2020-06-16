class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {

        if(v.size() <= 1)
            return v;

        int i,j,maxxIdx=0,n=v.size(),maxxLen=1,maxx,idx;

        vector<vector<int>> res(n,vector<int>());
        sort(v.begin(),v.end());

        for(i=n-1;i>=0;i--)
        {
            res[i].push_back(v[i]);
            j = i + 1;
            maxx = 0;
            idx = i;
            while(j<n)
            {
                if(v[j] % v[i] == 0 && res[j].size() > maxx)
                {
                    maxx = res[j].size();
                    idx = j;
                }
                j+=1;
            }
            if(idx != i)
            {
                res[i].insert(res[i].end(),res[idx].begin(),res[idx].end());
                if(maxx + 1 > maxxLen)
                {
                    maxxLen = maxx + 1;
                    maxxIdx = i;
                }
            }
        }
        return res[maxxIdx];
    }
};
