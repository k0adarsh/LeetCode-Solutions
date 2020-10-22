class Solution {
public:
    int hIndex(vector<int>& v) {

        int flag=0,i,n=v.size(),ans;
        if(n==0)
            return 0;
        for(i=n-1;i>=0;i--)
        {
            if(v[i] >= (v.size() - i))
            {
                flag = 1;
                cout<<v[i]<<" "<<n-i<<endl;
                ans = i;
            }
        }
        if(flag)
            return n-ans;
        return 0;
    }
};
