 bool comp(pair<int,int> &p1,pair<int,int> &p2)
    {
        if(p1.first < p2.first)
            return true;
        else if(p1.first == p2.first && p1.second < p2.second)
            return true;
        return false;
    }
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        long long int diff;
        int i,n=nums.size(),j;
        if(n<=1)
            return false;
        vector<pair<int,int>> v;

        for(i=0;i<n;i++)
            v.push_back(make_pair(nums[i],i));

        sort(v.begin(),v.end(),comp);

        //for(i=0;i<v.size();i++)
            //cout<<v[i].first<<" "<<v[i].second<<endl;

        i = 0;j=0;
        while(i < n && j < n)
        {
            if(i == j)
            {
                j+=1;
                continue;
            }
            diff = (long)v[j].first - (long)v[i].first;
            //cout<<diff<<endl;
            diff = abs(diff);
            if(diff <= t)
            {
                if(abs(v[j].second - v[i].second) <= k)
                    return true;
                j+=1;
            }
            else
                i+=1;
        }
        return false;
    }
};
