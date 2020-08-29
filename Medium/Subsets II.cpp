class Solution {
public:
    void subSets(vector<int> &nums, vector<int> temp, vector<vector<int>> &ans, int i)
    {
        if(i == nums.size())
        {
            ans.push_back(temp);
            return ;
        }

        temp.push_back(nums[i]);
        subSets(nums,temp,ans,i+1);

        while(i < nums.size() - 1 && nums[i] == nums[i+1])
            i+=1;

        temp.pop_back();
        subSets(nums,temp,ans,i+1);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        if(nums.size() == 0)
            return ans;

        sort(nums.begin(),nums.end());

        subSets(nums,temp,ans,0);
        return ans;
    }
};
