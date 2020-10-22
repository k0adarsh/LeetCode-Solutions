class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {

        int n = v.size(),i;
        vector<int> lft,rgt(n,1);
        lft.push_back(1);
        for(i=1;i<n;i++)
            lft.push_back(lft[i-1]*v[i-1]);

        for(i=n-2;i>=0;i--)
            rgt[i] = rgt[i+1]*v[i+1];

        for(i=0;i<n;i++)
            lft[i] *= rgt[i];
        return lft;
    }
};
