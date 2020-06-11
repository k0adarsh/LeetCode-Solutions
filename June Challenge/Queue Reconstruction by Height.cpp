bool comp(vector<int>&v1,vector<int>&v2)
    {
        if(v1[0]<=v2[0])
        {
            if(v1[0]==v2[0])
               return v1[1] < v2[1] ? true : false;
            return true;
        }
        return false;
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {

        int n = p.size(),i,j,k;
        vector<vector<int>> res;
        if(n==0)
            return res;
        vector<vector<int>> ans(n,vector<int>(2,-1));
        sort(p.begin(),p.end(),comp);

        ans[p[0][1]][0] = p[0][0];
        ans[p[0][1]][1] = p[0][1];
        cout<<p[0][0]<<" inserted at "<<p[0][1]<<endl;
        for(i=1;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((ans[j][0]==-1 && ans[j][1]==-1 ) || ans[j][0] == p[i][0])
                {
                     k = p[i][1];

                    if(ans[j][0] == p[i][0])
                         k-=ans[j][1];

                     while(k>0 && j<n)
                     {
                         if((ans[j][0]==-1 && ans[j][1]==-1) || ans[j][0] == p[i][0])
                             k-=1;
                         j+=1;
                     }
                     while(ans[j][0]!=-1 && ans[j][1]!=-1)
                        j+=1;

                     ans[j][0] = p[i][0];
                     ans[j][1] = p[i][1];

                     cout<<p[i][0]<<" "<<p[i][1]<<" inserted on "<<j<<endl;
                     break;
                }
            }
        }
        return ans;
    }

};
