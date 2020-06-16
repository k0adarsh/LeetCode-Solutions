class Solution {
public:

    vector<vector<int>> ans;
    void findPer(vector<int> &v, int i)
    {
        int n = v.size(),j;
        if(i==n-1)
        {
            ans.push_back(v);
            return ;
        }
        for(j=i;j<n;j++)
        {
            swap(v[i],v[j]);
            findPer(v,i+1);
            swap(v[i],v[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& v) {

        findPer(v,0);
        return ans;
    }
};
