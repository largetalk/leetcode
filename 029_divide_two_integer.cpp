/*
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * The integer division should truncate toward zero.
 *
 * Example 1:
 *
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Example 2:
 *
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Note:
 *
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
 */


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(!dividend)
                return 0;
            long long arr[33];
            arr[0] = 1;
            for (int i=1; i< 33; i++) {
                arr[i] = arr[i-1] * 2;
            }
            long long temp1 = dividend, temp2 = divisor;
            if (temp1 < 0)
                temp1 = -temp1;
            if (temp2 < 0)
                temp2 = -temp2;
            long long res, pre = 0, ret = 0;
            int i = 0;
            while(1) {
                res = pre + arr[i] * temp2;
                if (res > temp1) {
                    if (!i)
                        break;
                    pre = pre + arr[i-1] * temp2;
                    ret += arr[i-1];
                    i =0;
                } else {
                    i++;
                }
            }
            if ((dividend ^ divisor) < 0)
                ret = -ret;
            if (ret == 2147483648)
                return ret -1;
            return ret;
        }

};


int main(int argc, const char * argv[]) {
    Solution s = Solution();
    //int a = 10^3;
    //int b = -7^3;
    //int c = 7^-3;
    //int d = -7^-3;
    //cout << a << '\n';
    //cout << b << '\n';
    //cout << c << '\n';
    //cout << d << '\n';
    cout << s.divide(7, -3) << '\n';
    cout << s.divide(10, 3) << '\n';
    cout << s.divide(-2147483647, -1) << '\n';
}


