class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {

        int countt = 0;
        while(m!=n)
        {
            m = m >> 1;
            n = n >> 1;
            countt+=1;
        }
        return m << countt;
    }
};
