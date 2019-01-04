/*
   Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

   If the fractional part is repeating, enclose the repeating part in parentheses.

   Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"

*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

class Solution {

    public:
        void join_str(string& s, long long num, int t) {
            if (!num) {
                if (t < 0)
                    s.push_back('-');
                s.push_back('0');
                return;
            }
            while (num) {
                s.push_back(num % 10 + '0');
                num /= 10;
            }
            if (t < 0) {
                s.push_back('-');
            }
            reverse(s.begin(),s.end());
        }
        string fractionToDecimal(int numerator, int denominator) {
            map<long long, int> m;
            if (!numerator)
                return "0";
            int t = 1;
            long long n1 = numerator, d1 = denominator;
            if (numerator < 0) {
                t *= -1;
                n1 *= -1;
            }
            if (denominator < 0) {
                t *= -1;
                d1 *= -1;
            }
            long long num = n1 / d1;
            string ans;
            join_str(ans, num, t);
            long long quotient = n1 % d1;
            if (quotient)
                ans.push_back('.');
            string temp;
            int count1 = 0;
            while(quotient) {
                long long new_num = quotient * 10;
                if (m[new_num]) {
                    temp.push_back(')');
                    count1 = m[new_num];
                    break;
                }
                m[new_num] = temp.length() + 1;
                temp.push_back(new_num / d1 + '0');
                quotient = new_num % d1;
            }
            if (count1) {
                ans.append(temp.begin(), temp.begin() + count1 -1);
                ans.push_back('(');
                ans.append(temp.begin() + count1 -1, temp.end());
            } else {
                ans.append(temp.begin(), temp.end());
            }
            return ans;
        }


};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    string index = s.fractionToDecimal(2, 3);
    cout << index << '\n';
    return 0;
}
