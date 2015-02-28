//
//Given two numbers represented as strings, return multiplication of the numbers as a string.
//
//Note: The numbers can be arbitrarily large and are non-negative.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

class Solution {
    public:
        string multiply(string num1, string num2) {
            string total = "";

            for (int i = num1.length()-1;i >=0;i--) {
                int k = 0;
                string tmp = "";
                for (int j = num2.length()-1;j>=0;j--) {
                    int m = int(num1[i]) - 48;
                    int n = int(num2[j]) - 48;
                    int mul = m * n + k;
                    k = mul/10;
                    char s[2];
                    sprintf(s, "%d", mul%10);
                    tmp = s + tmp;
                }
                if (k!=0) {
                    char s[2];
                    sprintf(s, "%d", k);
                    tmp = s + tmp;
                }
                while (tmp.length() > 1 && tmp[0] == '0') {
                    tmp = tmp.erase(0,1);
                }
                if (tmp != "0") {
                for (int x=0; x < num1.length() - 1  - i; x++) {
                    tmp += "0";
                }
                }
                total = sadd(total, tmp);
            }
            //for (int i=0; i < total.length()-1; i++) {
            //    if (total[i] == '0') {
            //        total.erase(0,1);
            //    } else {
            //        break;
            //    }
            //}
            return total;
        }


        string sadd(string num1, string num2) {
            int i = num1.length();
            int j = num2.length();

            int k = 0;
            string res = "";
            for (;i > 0 && j> 0; i--, j--) {
                int m = int(num1[i-1]) - 48;
                int n = int(num2[j-1]) - 48;
                int mul = m + n + k;
                k = mul/10;
                char s[2];
                sprintf(s, "%d", mul%10);
                res = s + res;
            }
            while (i>0) {
                if (k!=0) {
                    int m = int(num1[i-1]) - 48;
                    int sum = m + k;
                    k = sum/10;
                    char s[2];
                    sprintf(s, "%d", sum%10);
                    res = s + res;
                } else {
                    res = num1[i-1] + res;
                }
                i--;
            }

            while (j>0) {
                if (k!=0) {
                    int n = int(num2[j-1]) - 48;
                    int sum = n + k;
                    k = sum/10;
                    char s[2];
                    sprintf(s, "%d", sum%10);
                    res = s + res;
                } else {
                    res = num2[j-1] + res;
                }
                j--;
            }
            if (k!=0) {
                char s[2];
                sprintf(s, "%d", k);
                res = s + res;
            }
            return res;
        }
};


int main(int argc, const char * argv[]) {
    Solution s = Solution();
    cout << s.sadd("", "11") << endl;
    cout << s.sadd("2", "4") << endl;
    cout << s.sadd("3", "6") << endl;
    cout << s.sadd("11", "11") << endl;
    cout << s.sadd("999", "22") << endl;
    cout << s.sadd("99", "222") << endl;
    cout << "################" << endl;

    cout << s.multiply("2", "4") <<endl;
    cout << s.multiply("3", "6") << endl;
    cout << s.multiply("11", "11") << endl;
    cout << s.multiply("999", "22") << endl;
    cout << s.multiply("99", "222") << endl;
    cout << s.multiply("9133", "0") << endl;
    cout << s.multiply("0", "52") << endl;
    cout << s.multiply("0", "1720") << endl;
}
