class Solution {
public:
    int rob(vector<int>& v) {

        int n=v.size(),i;
        if(n==0)
            return 0;
        if(n==1)
            return v[0];
        if(n==2)
            return max(v[0],v[1]);

        int dp0[n-1],dp1[n-1];

        dp0[0] = v[0];
        dp0[1] = max(v[0],v[1]);

        for(i=2;i<n-1;i++)
            dp0[i] = max(dp0[i-1],dp0[i-2]+v[i]);

        dp1[0] = v[1];
        dp1[1] = max(v[1],v[2]);

        for(i=2;i<n-1;i++)
            dp1[i] = max(dp1[i-1],dp1[i-2]+v[i+1]);

        return max(dp0[n-2],dp1[n-2]);
    }
};
