class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        int n = costs.size(),i,ans=0;
        vector<int> difArr;
        for(i=0;i<n;i++)
        {
            ans += costs[i][0];
            difArr.push_back(costs[i][1] - costs[i][0]);
        }
        cout<<ans<<endl;
        sort(difArr.begin(),difArr.end());

        for(i=0;i<n/2;i++)
            ans += difArr[i];
        return ans;
    }
};
