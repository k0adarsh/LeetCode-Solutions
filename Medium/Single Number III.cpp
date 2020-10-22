class Solution {
public:
    vector<int> singleNumber(vector<int>& v) {

        int n=v.size(),i,res=0,x=0,y=0;
        vector<int> ans;

        for(i=0;i<n;i++)
            res ^= v[i];
        res = res & ~(res-1);
        //cout<<res<<endl;
        for(i=0;i<n;i++)
        {
            if(v[i] & res)
               x ^= v[i];
            else
               y ^= v[i];
        }

        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};
