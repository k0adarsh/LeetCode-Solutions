class Solution {
public:
    double calcPower(double x, int n)
    {
        if(n==0)
            return 1;
        if(x == 0 || x == 1 || n == 1)
            return x;

        double ans = calcPower(x,n/2);
        if(n%2==0)
            return ans*ans;
        else
            return ans*ans*x;

    }
    double myPow(double x, int n) {

        if(n < 0)
        {
            x = 1/x;
            n = abs(n);
        }
       return calcPower(x,n);
    }
};
