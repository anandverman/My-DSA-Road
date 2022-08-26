/*
50. Pow(x, n)
Medium

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

 

Constraints:

    -100.0 < x < 100.0
    -231 <= n <= 231-1
    -104 <= xn <= 104

*/

//Optimized Recursive Code for +ve and -ve powers

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0 or x==1)
            return 1;
        if(n<0)
        {
            double sub=myPow(x,n/2);
            sub*=sub;
            if(n&1)
                return sub/x;
            return sub;
        }
        
        double subpow=myPow(x,n/2);
        subpow=subpow*subpow;
        if(n&1)
            return x*subpow;
        return subpow;
    }
};