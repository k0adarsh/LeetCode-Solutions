class Solution {
public:
    int evalRPN(vector<string>& v) {
        int i,res,op1,op2,x;
        stack <int> s;
        if(v.size()==0)
            return 0;
        for(i=0;i<v.size();i++)
        {
            if(v[i]=="+" || v[i]=="-" || v[i]=="/" || v[i]=="*")
            {
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                if(v[i]=="+")
                    res = op2 + op1;
                if(v[i]=="-")
                    res = op2 - op1;
                if(v[i]=="*")
                    res = op2 * op1;
                if(v[i]=="/")
                    res = op2 / op1;
                s.push(res);
            }
            else
            {
                x = stoi(v[i]);
                s.push(x);
            }
        }
        return s.top();
    }
};
