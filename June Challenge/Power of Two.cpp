class Solution {
public:
    bool isPowerOfTwo(int n) {
        int r,q;
        while(n)
        {
            r = n%2;
            n = n/2;
            if(r==1)
            {
                if(n==0)
                    return true;
                return false;
            }
        }
        return false;
    }
};
