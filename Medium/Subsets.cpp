class Solution {
public:

    void findSubsets(vector<int> &v, int i,vector<int> temp,vector<vector<int>> &ans)
    {
        if(i == v.size())
        {
            ans.push_back(temp);
            return;
        }
        findSubsets(v,i+1,temp,ans);
        temp.push_back(v[i]);
        findSubsets(v,i+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> temp;
        vector<vector<int>> ans;
        findSubsets(nums,0,temp,ans);
        return ans;
    }
};
