class Solution {
public:
    int singleNumber(vector<int>& v) {

        int t = 0,n=v.size(),i,countt;
        long ans = 0;
        while(t<32)
        {
            countt = 0;
            for(i=0;i<n;i++)
            {
                if(v[i] & 1)
                    countt+=1;
                v[i] = v[i]>>1;
            }
            if(countt%3 == 1)
                ans += pow(2,t);
            //cout<<ans<<endl;
            t+=1;
        }
        return ans;
    }
};
