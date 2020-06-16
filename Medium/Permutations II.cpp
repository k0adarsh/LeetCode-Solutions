class Solution {
public:

    vector<vector<int>> ans;
    void findPer(vector<int> &v, int i)
    {
        int n = v.size(),j,k,flag;
        if(i==n-1)
        {
            ans.push_back(v);
            return ;
        }
        for(j=i;j<n;j++)
        {
            flag = 0;
            for(k=i;k<j;k++)
            {
                if(v[j] == v[k])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                continue;
            swap(v[i],v[j]);
            findPer(v,i+1);
            swap(v[i],v[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& v) {

        sort(v.begin(),v.end());
        findPer(v,0);
        return ans;
    }
};
