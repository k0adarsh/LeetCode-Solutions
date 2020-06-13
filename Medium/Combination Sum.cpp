class Solution {
public:

void targetsum(vector<int> &v,int t,int curr,int i,vector<int> aux, vector<vector<int>> &ans)
{
    if(curr > t)
        return ;
    if(i == v.size())
    {
        if(curr==t)
            ans.push_back(aux);
        return;
    }
     aux.push_back(v[i]);
    targetsum(v,t,curr+v[i],i,aux,ans);
    aux.pop_back();
    //while(v[i+1]==v[i])
    //i+=1;
    targetsum(v,t,curr,i+1,aux,ans);

}

vector<vector<int>> combinationSum(vector<int>& v, int t) {

        vector <int> aux;
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        targetsum(v,t,0,0,aux,ans);
        sort(ans.begin(),ans.end());
        return ans;

    }
};
