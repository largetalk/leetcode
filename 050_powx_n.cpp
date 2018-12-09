/*
 * Implement pow(x, n), which calculates x raised to the power n (xn).

 Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
    public:
        double Pow(double x, long long n)
        {
            if(!n)
                return 1;
            if(n == 1)
                return x;
            double temp = Pow(x,(n)/ 2);
            double ret;
            if(n&1)
                ret = temp * temp * x;
            else
                ret = temp * temp;
            return ret;
        }
        double myPow(double x, int n) {
            long long k = n;
            if(n < 0)
                x = 1 / x;
            return Pow(x,n);
        }

};


int main(int argc, const char * argv[]) {
    Solution s = Solution();

    double x = 2.0;
    int n = -2147483648;
    double result = s.myPow(x, n);
    cout << result << '\n';

}

