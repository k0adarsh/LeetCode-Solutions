class Solution {
public:
    int maxArea(vector<int>& v) {

        int i,j,n = v.size(),ans=0,res;
        i = 0;
        j = n-1;

        while(i<j)
        {
            res = min(v[i],v[j])*(j-i);
            ans = max(res,ans);

            if(v[i] > v[j])
                j-=1;
            else
                i+=1;
        }
        return ans;
    }
};
