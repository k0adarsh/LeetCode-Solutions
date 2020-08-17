class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {

        int i,j,n = v.size(),sum,c=0;
        map<int,int> m;
        vector<int> res;
        vector<vector<int>> ans;
        if(n < 3)
            return ans;
        sort(v.begin(),v.end());
        for(i=0;i<n;i++)
            m[v[i]] = i+1;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                sum = v[i] + v[j];
                if(m[-sum] && m[-sum] > i+1 && m[-sum] > j+1)
                {
                    res.push_back(v[i]);
                    res.push_back(v[j]);
                    res.push_back(-sum);
                    ans.push_back(res);

                    res.clear();
                }
                while(j < n-1 && v[j]==v[j+1])
                        j+=1;
            }
            while(i < n-1 && v[i]==v[i+1])
                i+=1;
        }
        return ans;
    }
};
