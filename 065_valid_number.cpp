/*
 * Validate if a given string can be interpreted as a decimal number.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 *
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:
 *
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 * Of course, the context of these characters also matters in the input.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        void blank(int& i, string& s) {
            while(i<s.length() && s[i] == ' ')
                i++;
        }
        bool firstHalf(int& i, string& s) {
            int num=0;
            for(;i<s.length();i++) {
                if (isdigit(s[i]))
                    continue;
                else if (s[i]=='.') {
                    if (num)
                        return false;
                    num++;
                } else if (s[i]=='e' || s[i]==' ') {
                    return true;
                } else {
                    return false;
                }
            }
            return true;
        }

        bool secondHalf(int& i, string& s) {
            if (i==s.length()) 
                return 0;
            if (s[i]=='-' || s[i] == '+') {
                i++;
            }
            if (!isdigit(s[i]))
                return 0;
            for (;i<s.length();i++) {
            if (!isdigit(s[i])) {
                if (s[i] == ' ')
                    return 1;
                return 0;
            }
            }
            return true;
        }

        bool isNumber(string s) {
            int i=0;
            if(!s.length()) {
                return false;
            }
            blank(i, s);
            if (i==s.length())
                return false;
            if (s[i] == '-' || s[i] == '+')
                i++;
            int temp = i;
            if (!firstHalf(i, s))
                return false;
            if (i==temp)
                return false;
            if (i-1 == temp && s[i-1]=='.')
                return 0;
            if (i==s.length())
                return true;
            if (s[i]=='e') {
                i++;
                if (!secondHalf(i,s))
                    return 0;
            }
            blank(i,s);
            return i==s.length();

        }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    cout << s.isNumber("0") << '\n';
    return 0;
}
