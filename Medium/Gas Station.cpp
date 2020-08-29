class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int curr = 0,st=0,i,flag=0,n = gas.size();
        while(st < n)
        {
            cout<<"starting from "<<st<<endl;
            curr = 0;
            flag = 0;
            for(i=0;i<n;i++)
            {
                curr += (gas[(st+i)%n] - cost[(st+i)%n]);
                cout<<"curr = "<<curr<<endl;
                if(curr == 0 && i==n-1)
                    break;
                if(curr <= 0)
                {
                    flag = 1;
                    st = max(st+1,(st+i+1)%n);
                    if(st==n)
                        return -1;
                    cout<<"start set to "<<st<<endl;
                    break;
                }
            }
            if(flag==0)
                return st;
        }
        return st;
    }
};
