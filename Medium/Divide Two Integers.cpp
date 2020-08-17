class Solution {
public:
    int divide(int dividend, int divisor) {

        long long int dvd = dividend;
        long long int dvs = divisor;
        long long int temp = 0,m = 0,q = 1,quo = 0;


        if(dvd == INT_MIN)
        {
            if(dvs == 1)
                return INT_MIN;
            if(dvs == -1)
                return INT_MAX;
        }
        dvd = llabs(dvd);
        dvs = llabs(dvs);

        while(dvd >= dvs)
        {
            temp = dvs;
            q = 1;
            while(dvd >= 2*temp)
            {
                temp += temp;
                q += q;
            }
            dvd -= temp;
            quo += q;
        }
        if((dividend > 0 && divisor > 0) || (dividend < 0 &&  divisor < 0))
            return quo;
        return -quo;
    }
};
