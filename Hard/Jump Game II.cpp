class Solution {
public:
    int jump(vector<int>& v) {

        int n = v.size(),i,j,step = 1;
        vector<int> dp(n,INT_MAX);

        if(n<=1)
            return 0;

        int curr = v[0];
        int maxx = v[0];

        for(i=1;i<n;i++)
        {
            maxx = max(maxx,i + v[i]);
            if(i==n-1)
                break;
            curr -= 1;
            if(curr == 0)
            {
                step += 1;
                curr = maxx - i;
            }
            //cout<<i<<" "<<curr<<" "<<maxx<<endl;
        }
        return step;
    }
};
