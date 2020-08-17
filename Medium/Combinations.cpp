class Solution {
public:
    void findSubsets(int i,int n,vector<int> temp,vector<vector<int>> &ans, int k)
    {
        if(i > n)
        {
            if(temp.size() == k)
                ans.push_back(temp);
            return;
        }
        if(temp.size() + n - i >= k)
            findSubsets(i+1,n,temp,ans,k);
        if(temp.size() <= k)
        {
           temp.push_back(i);
           findSubsets(i+1,n,temp,ans,k);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        findSubsets(1,n,temp,ans,k);
        return ans;
    }
};
