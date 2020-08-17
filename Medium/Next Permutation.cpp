class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int i,n = nums.size(),flag=0,j,res=INT_MAX,ind;

        for(i=n-1;i>=1;i--)
        {
            if(nums[i] > nums[i-1])
            {
                for(j=i-1;j<n;j++)
                {
                    if(nums[j] > nums[i-1] && nums[j] < res)
                    {
                        res = nums[j];
                        ind = j;
                    }
                }
                swap(nums[i-1],nums[ind]);
                break;
            }
        }
        sort(nums.begin() + i,nums.end());
    }
};
