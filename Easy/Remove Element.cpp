class Solution {
public:
    int removeElement(vector<int>& v, int x) {

        int i = 0,j = 0,n = v.size(),countt=0;
        while(i<n)
        {
            while(i<n && v[i]==x)
                i+=1;
            if(i < n)
            {
                v[j] = v[i];
                j+=1;
                i+=1;
                countt+=1;
            }
        }
        return countt;
    }
};
