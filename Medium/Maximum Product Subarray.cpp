class Solution {
public:
    int maxProduct(vector<int>& a) {

        int n=a.size(),i,maxx,minn,ans=INT_MIN;
        if(n==0)
            return 0;
        maxx = a[0];
        minn = a[0];
        ans = a[0];
        for(i=1;i<n;i++)
        {
            if(a[i]<0)
                swap(maxx,minn);
            maxx = max(a[i],maxx*a[i]);
            minn = min(a[i],minn*a[i]);

            ans = max(maxx,ans);
        }
        ans = max(maxx,ans);
        return ans;
    }
};
