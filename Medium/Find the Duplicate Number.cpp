class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int i,ind;

        for(i=0;i<nums.size();i++)
        {
            ind = abs(nums[i]);
            if(nums[ind] < 0)
                return ind;
            else
                nums[ind] = -nums[ind];
        }
        return ind;
    }
};
