class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size(),i;
        if(n <= 2)
            return n;

        int countt = 0,freq=0;

        for(i=n-1;i>=1;i--)
        {
            if(nums[i] == nums[i-1])
            {
               if(freq < 2)
               {
                  nums.push_back(nums[i]);
                  freq += 1;
                  countt+=1;
               }
               else
                  freq+=1;
            }
            else
            {
                if(freq < 2)
                {
                    nums.push_back(nums[i]);
                    countt+=1;
                }
                freq = 0;
            }
        }
        if(freq < 2)
        {
            nums.push_back(nums[0]);
            countt+=1;
        }
        reverse(nums.begin(),nums.end());
        return countt;
    }
};
