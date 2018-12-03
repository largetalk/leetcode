/*
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * Example 2:
 *
 * Input: "cbbd"
 * Output: "bb"
 */


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
        string longestPalindrome(string s) {
            int dp[1000][1000] = {0};
            int beg=0;
            int end=1;
            int ans = 0;
            int len = s.length();
            for(int i=0; i < len; i++) {
                dp[i][i] = 1;
                if (i + 1 < len && s[i] == s[i+1]) {
                    dp[i][i+1] = 1;
                }
            }
            for(int i=0; i < len; i++) {
                for (int j=0; j <= i; j++) {
                    if (i > j + 1) {
                        dp[j][i] = (dp[j+1][i-1] && s[i] == s[j]);
                    }
                    cout << "#i " << i << ' ' << j << ' ' << dp[j][i] << '\n';
                    if (dp[j][i] && i - j + 1 > ans) {
                        cout << j << ' ' << i << ' ' << ans << '\n';
                        ans = i - j + 1;
                        beg = j;
                        end = i + 1;
                    }
                }
            }
            string ret(s.begin() + beg,s.begin() + end);
            return ret;
        }
};


int main(int argc, const char * argv[]) {
    Solution s = Solution();

    //cout << s.longestPalindrome("babad") << '\n';
    //cout << s.longestPalindrome("") << '\n';
    cout << s.longestPalindrome("abb") << '\n';
}

